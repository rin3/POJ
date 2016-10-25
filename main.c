/* POJ 1009 */

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

int main() {
	/* iterators */
	int i, j, k;
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
	/* computed edge value */
	int nEV;

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

		/* processing of the output image */

		/* reset run length */
		nL = 0;
		/* reset edge valus as non-existent */
		nV = -1;

		/* create output image */
		for(j = 0; j < nHeight; j++) {
			for(i =0; i < nWidth; i++) {
				/* compute edge pixel value */
				nEV = getEdge(i,j, RLP, nWidth, nHeight);
				if(nEV == nV) {
					/* value same as before */
					++nL;
					continue;
				}

				/* now edge value is different than before */

				/* unless very first of the image */
				if(nL > 0) {
					/* print a single line of result */
					printf("%d %d\n", nV, nL);
				}

				/* set new variables */
				nL = 1;
				nV = nEV;
			}
		}
		/* print the final line of output */
		printf("%d %d\n", nV, nL);
		printf("0 0\n");
	}

	return 0;
}