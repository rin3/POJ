/* POJ 1009 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

/* maximum number of RLPs */
#define MAX_PAIR	1000
/* surroundings */
#define BOX_SIZE	9

/* type for run length pairs */
typedef struct RLP_t {
	/* value */
	int nVal;
	/* position */
	int nPos;
} RLP;


/* compare function for qsort */
int compInt(const void* pa, const void* pb) {
	/* simple integer comparison */
	return (*(int*)pa - *(int*)pb);
}

/* get pixel value in the input image */
int getValue(int _nIdx, RLP* _tIn) {
	/* initialize index */
	int n = 0;

	while(TRUE) {
		if(_nIdx > _tIn[n].nPos) {
			/* given index is bigger than the one in the array element */
			++n;
			continue;
		}
		return _tIn[n].nVal;
	}
}

/* compute edge from 1-based index */
int getEdge(int _nIdx, RLP* _tIn, int _nW, int _nPair) {
	/* initialize the edge */
	int nE = 0;
	/* temporary */
	int t;

	/* upper middle */
	if(_nIdx > _nW) {
		t = abs(getValue(_nIdx - _nW, _tIn) - getValue(_nIdx, _tIn));
		if(t > nE) {
			nE = t;
		}
	}

	/* lower middle */
	if(_nIdx + _nW <= _tIn[_nPair - 1].nPos) {
		t = abs(getValue(_nIdx + _nW, _tIn) - getValue(_nIdx, _tIn));
		if(t > nE) {
			nE = t;
		}
	}

	/* middle left */
	if(_nIdx % _nW != 1) {
		t = abs(getValue(_nIdx - 1, _tIn) - getValue(_nIdx, _tIn));
		if(t > nE) {
			nE = t;
		}
	}

	/* middle right */
	if(_nIdx % _nW != 0) {
		t = abs(getValue(_nIdx + 1, _tIn) - getValue(_nIdx, _tIn));
		if(t > nE) {
			nE = t;
		}
	}

	/* upper left */
	if(_nIdx % _nW != 1 && _nIdx - _nW - 1 > 0) {
		t = abs(getValue(_nIdx - _nW - 1, _tIn) - getValue(_nIdx, _tIn));
		if(t > nE) {
			nE = t;
		}
	}

	/* upper right */
	if(_nIdx % _nW != 0 && _nIdx - _nW + 1 > 0) {
		t = abs(getValue(_nIdx - _nW + 1, _tIn) - getValue(_nIdx, _tIn));
		if(t > nE) {
			nE = t;
		}
	}

	/* lower left */
	if(_nIdx % _nW != 1 && _nIdx + _nW - 1 <= _tIn[_nPair - 1].nPos) {
		t = abs(getValue(_nIdx + _nW - 1, _tIn) - getValue(_nIdx, _tIn));
		if(t > nE) {
			nE = t;
		}
	}

	/* lower right */
	if(_nIdx % _nW != 0 && _nIdx + _nW + 1 <= _tIn[_nPair - 1].nPos) {
		t = abs(getValue(_nIdx + _nW + 1, _tIn) - getValue(_nIdx, _tIn));
		if(t > nE) {
			nE = t;
		}
	}

	/* return max difference */
	return nE;
}

/* main */
int main() {
	/* iterators */
	int i, j;
	/* image width */
	int nW;
	/* run length pair */
	int nV;
	int nL;
	/* number of RLPs */
	int nPair;
	/* RLP array */
	RLP tIn[MAX_PAIR];
	/* index array */
	int nIdx[MAX_PAIR * BOX_SIZE];
	/* last indices number in the index array */
	int nBaseIdx, nLastIdx;
	/* last edge value in the composition of output */
	int nLastEdge;

	/*--- start ---*/

	/* read input */
	while(scanf("%d", &nW) == 1) {

		/* print output */
		printf("%d\n", nW);

		if(nW == 0) {
			/* end of input */
			break;
		}

		/*--- processing of an image ---*/

		/* reset number of RLPs */
		nPair = 0;

		/* read RLPs into the array */
		while(scanf("%d %d", &nV, &nL) == 2) {

			if(nV == 0 && nL == 0) {
				/* end of an image */
				break;
			}

			/* store elements in the array */
			tIn[nPair].nVal = nV;
			if(nPair == 0) {
				/* initial pair */
				tIn[nPair].nPos = nL;
			} else {
				/* otherwise add up length for index */
				tIn[nPair].nPos = nL + tIn[nPair - 1].nPos;
			}

			/* fill index array, w/input image, in segment 0 to (nPair-1) */
			nIdx[nPair] = tIn[nPair].nPos;
printf("- %d %d\n", tIn[nPair].nVal, tIn[nPair].nPos);
			/* increment RLP array index */
			++nPair;
		}

		/* fill index array w/surrounding pixels */
		for(i = 0; i < nPair; i++) {
			for(j = -1; j <= 1; j++) {
				/* upper row */
				nIdx[(j + 2) * nPair + i] = nIdx[i] - nW + j;
				/* [nPair]...[2*nPair-1] = upper left pixel */
				/* [2*nPair]...[3*nPair-1] = upper middle pixel */
				/* [3*nPair]...[4*nPair-1] = upper right pixel */

				/* lower row */
				nIdx[(j + 7) * nPair + i] = nIdx[i] + nW + j;
				/* [6*nPair]...[7*nPair-1] = lower left pixel */
				/* [7*nPair]...[8*nPair-1] = lower middle pixel */
				/* [8*nPair]...[9*nPair-1] = lower right pixel */
			}
			/* middle row */
			nIdx[4 * nPair + i] = nIdx[i] - 1;
			nIdx[5 * nPair + i] = nIdx[i] + 1;
			/* [4*nPair]...[5*nPair-1] = middle left pixel */
			/* [5*nPair]...[6*nPair-1] = middle right pixel */
		}

		/* sort index array */
		qsort(nIdx, BOX_SIZE * nPair, sizeof(int), compInt);

for(i = 0; i<9*nPair; i++) {
	printf("$ %d\n", nIdx[i]);
}
		/* initialize the last indices */
		nBaseIdx = 0;
		nLastIdx = 0;
		/* initialize the last edge, as non-existent */
		nLastEdge = -1;
		/* iterate over sorted index array */
		for(i = 0; i < BOX_SIZE * nPair; i++) {
			/* read current index into (nL) */
			nL = nIdx[i];
			if(nL < 0 || (i > 0 && nL == nIdx[i - 1])) {
				/* if index is zero or negative, or the same as the privious one */
				continue;
			}

			/* new index found */
			nV = getEdge(nL, tIn, nW, nPair);
/*printf("D- %d %d\n", nL, nV);*/
			if(nV != nLastEdge) {
				/* you've got a new edge */
				if(nLastIdx != 0) {
					/* unless the very first bit, print a single result line */
					printf("%d %d\n", nLastEdge, nLastIdx - nBaseIdx);
				}
				/* update edge value */
				nLastEdge = nV;
				/* update last indices */
				nBaseIdx = nLastIdx;
			}
				nLastIdx = nL;

			/* when you've reached the end of an image, print the last line of result */
			if(nL == tIn[nPair - 1].nPos) {
				printf("%d %d\n", nV, nL - nBaseIdx);	
				/* quit the for loop */
				break;
			}

			/* if the new edge value is the same as before, don't count, do nothing */
			/* keep the last index (nLastIdx) and edge value */
		}
		/* print end of an image */
		printf("0 0\n");
	}
	return 0;
}