/* POJ 1009 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

/* maximum number of RLPs */
#define MAX_PAIR	1000
/* surroundings */
#define SURROUND	8

/* type for run length pairs */
typedef struct RLP_t {
	int nVal;
	int nIdx;
} RLP;

int main() {
	/* iterators */
	int i;
	/* image width */
	int nW;
	/* run length pair */
	int nV;
	int nL;
	/* number of RLPs */
	int nP;
	/* RLP arrays */
	/* input image */
	RLP tIn[MAX_PAIR];
	/* surrounding pixels */
	RLP tSr[SURROUND][MAX_PAIR];

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
		nP = 0;

		/* read RLPs into the array */
		while(scanf("%d %d", &nV, &nL) == 2) {

			if(nV == 0 && nL == 0) {
				/* end of an image */
				break;
			}

			/* store elements in the array */
			tIn[nP].nVal = nV;
			tIn[nP].nLen = nL;

			/* increment RLP array index */
			++nP;
		}

		/*
			diffs -nW-1, -nW, -nW+1, -1, 0, 1, nW-1, nW, nW+1

			add -nW-1 to the first element
			add nW+1 to the last element 

			find point of difference = max 1000
		*/


	}

	
	return 0;
}