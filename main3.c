/* POJ 1009 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

/* maximum number of RLPs */
#define MAX_PAIR	1000
/* surroundings */
#define SURROUNDING_PIXELS	8

/* type for run length pairs */
typedef struct RLP_t {
	/* value */
	int nVal;
	/* position */
	int nPos;
} RLP;

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
	/* RLP arrays */
	/* input image */
	RLP tIn[MAX_PAIR];
	/* surrounding pixels */
	RLP tSr[SURROUNDING_PIXELS][MAX_PAIR];

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
printf("- %d %d\n", tIn[nPair].nVal, tIn[nPair].nPos);
			/* increment RLP array index */
			++nPair;
		}

		/* indexing surrounding pixels */
		for(i = 0; i < nPair; i++) {
			for(j = 0; j < SURROUNDING_PIXELS; j++) {
				tSr[j][i].nVal = tIn[i].nVal;
			}

			for(j = -1; j <= 1; j++) {
				/* upper row */
				tSr[j + 1][i].nIdx = tIn[i].nIdx - nW + j;
				/* tSr[0][i].nIdx = tIn[i].nIdx - nW - 1; */
				/* tSr[1][i].nIdx = tIn[i].nIdx - nW; */
				/* tSr[2][i].nIdx = tIn[i].nIdx - nW + 1; */

				/* lower row */
				tSr[j + 6][i].nIdx = tIn[i].nIdx + nW + j;
				/* tSr[5][i].nIdx = tIn[i].nIdx + nW - 1; */
				/* tSr[6][i].nIdx = tIn[i].nIdx + nW; */
				/* tSr[7][i].nIdx = tIn[i].nIdx + nW + 1; */
			}
			/* middle row */
			tSr[3][i].nIdx = tIn[i].nIdx - 1;
			tSr[4][i].nIdx = tIn[i].nIdx + 1;
		}

	}

	
	return 0;
}