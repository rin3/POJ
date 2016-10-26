/* POJ 1009 */
/* preparation for long runs
   introduction of head coord
   yet no real long run codes written
   only works with sample 1 & 3 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

/* run length encoding pair */
typedef struct RLEP_t {
	int nVal;
	int nRun;
	/* coord of the head */
	int nHeadX;
	int nHeadY;
} RLEP;

/* get pixel value from XY coord */
int getVal(int X, int Y, RLEP* _RLP, int _nWidth) {
	/* consecutive pixel counts */
	int nLen, nLenA;
	/* iterator */
	int i;

	/* pixel counts from coord */
	/* counts just before the coord itself */ 
	nLen = _nWidth * Y + X;

	/* reset count */
	nLenA = 0;

	/* iterate over RLE pairs */
	for(i = 0; ; i++) {
		nLenA += _RLP[i].nRun;

		/* check lengths */
		if(nLenA <= nLen) {
			/* proceed to the next pair */
			continue;
		}
		/* nLenA > nLen, ie. found value */
		break;
	}
	return _RLP[i].nVal;
}

/* compute edge value from XY coord */
int getEdge(int X, int Y, RLEP* _RLP, int _nWidth, int _nHeight) {
	int i, j;
	int nVal;

	int nDiff = 0;

	for(j = -1; j <= 1; j++) {
		for(i = -1; i <= 1; i++) {
			if(X + i >= 0 && X + i < _nWidth && Y + j >= 0 && Y + j < _nHeight) {
				nVal = abs(getVal(X + i, Y + j, _RLP, _nWidth) - getVal(X, Y, _RLP, _nWidth));
				if( nVal > nDiff) {
					nDiff = nVal;
				}
			}
		}
	}
	return nDiff;
}

/* produce output lines */
void prodOutput(int nXi, int nXe, int nYi, int nYe, \
RLEP* _RLP, int _nWidth, int _nHeight, int* pnV, int* pnL) {
	/* iterators */
	int i, j;
	/* computed edge value */
	int nEV;

	/* iterate over certain range according to input parameters */
	for(j = nYi; j <= nYe; j++) {
		for(i = nXi; i <= nXe; i++) {

			/* compute edge pixel value */
			nEV = getEdge(i, j, _RLP, _nWidth, _nHeight);
			if(nEV == *pnV) {
				/* value same as before */
				++(*pnL);
				continue;
			}

			/* now edge value is different than before */

			/* unless very first of the image */
			if(*pnL > 0) {
				/* print a single line of result */
				printf("%d %d\n", *pnV, *pnL);
			}

			/* set new variables */
			*pnL = 1;
			*pnV = nEV;
		}
	}
	
	return;
}

int main() {
	/* iterators */
	int i;
	/* image width and height */
	/* nHeight also keeps track of total pixel length */
	int nWidth, nHeight;
	/* pixel value */
	int nV;
	/* run length */
	int nL;
	/* RLE pairs array */
	RLEP RLP[1000];
	/* number of RLE pairs */
	int nPair;
	/* coord of the last head */
	int nLastX, nLastY;

	/* read input */
	while(scanf("%d", &nWidth) == 1) {

		/* print output */
		printf("%d\n", nWidth);

		if(nWidth == 0) {
			/* end of input */
			break;
		}

		/* processing of an image */

		/* reset the number of RLE pairs */
		nPair = 0;

		/* reset image height */
		/* also keeps track of total pixel length */
		nHeight = 0;

		/* read RLE pairs */
		while(scanf("%d %d", &nV, &nL) == 2) {

			if(nV == 0 && nL == 0) {
				/* end of an image */
				break;
			}

			/* fill RLE pair array */
			RLP[nPair].nVal = nV;
			RLP[nPair].nRun = nL;

			/* calculate total pixel length */
			nHeight += nL;

			/* calculate the coord head */
			/* note nHeight is total pixel length here */
			RLP[nPair].nHeadX = (nHeight - 1) % nWidth;
			RLP[nPair].nHeadY = (int)((nHeight - 1) / nWidth);

			/* increment RLE pair index */
			++nPair;
		}
		/* an image was read */

		/* compute image height */
		nHeight /= nWidth;

		/* processing of an output image */

		/* reset run length */
		nL = 0;
		/* reset edge valus as non-existent */
		nV = -1;

		/* initialize the last head */
		nLastX = -1;
		nLastY = 0;

		/* iterate over RLE pairs */
		for(i = 0; i < nPair; i++) {

			/* first line */
			if(nLastX < nWidth - 1) {
				/* last head is NOT at the end of a line */
				if(RLP[i].nHeadY == nLastY) {
					/* this run is on a single line */
					prodOutput(nLastX + 1, RLP[i].nHeadX, nLastY, nLastY, \
					RLP, nWidth, nHeight, &nV, &nL);
				} else {
					/* this run is over more than one line */
					/* fill till the end of a line */
					prodOutput(nLastX + 1, nWidth - 1, nLastY, nLastY, \
					RLP, nWidth, nHeight, &nV, &nL);
				}
			} else {
				/* nLastX == nWidth - 1 */
				/* last head IS at the end of a line */
			}

			/* lines in between */
			if(RLP[i].nHeadY >  nLastY + 1) {
				/* there exist lines in between */
				prodOutput(0, nWidth - 1, nLastY + 1, RLP[i].nHeadY - 1, \
				RLP, nWidth, nHeight, &nV, &nL);
			}

			/* last line */
			if(RLP[i].nHeadY > nLastY) {
				prodOutput(0, RLP[i].nHeadX, RLP[i].nHeadY, RLP[i].nHeadY, \
				RLP, nWidth, nHeight, &nV, &nL);
			}

			/* renew last head */
			nLastX = RLP[i].nHeadX;
			nLastY = RLP[i].nHeadY;
		}

		/* print the final line of output */
		printf("%d %d\n", nV, nL);
		printf("0 0\n");
	}

	return 0;
}