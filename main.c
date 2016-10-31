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
	printf("$$ %d\n", nIdx[i]);
}

		/* iterate over sorted index array */
		for(i = 0; i < BOX_SIZE * nPair; i++) {
			if(nIdx[i] < 0 || nIdx[i] == nIdx[i - 1]) {
				/* if index is negative, or the same as the privious */
				continue;
			}
		}


	}

	
	return 0;
}