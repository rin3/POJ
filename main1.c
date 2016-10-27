/* POJ 1009 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

/* maximum number of RLPs */
#define MAX_RLP		1000

/* type for run length pairs */
typedef struct RLP_t {
	int nVal;
	int nLen;
} RLP;

int main() {
	/* iterators */
	int i;
	/* image dimensions */
	int nWidth;
	/* run length pair */
	int nV;
	int nL;
	/* number of RLPs */
	int nPair;
	/* RLP arrays */
	/* input image */
	RLP tIn[MAX_RLP];
	/* differential array */
	RLP tDfL[2 * MAX_RLP];
	RLP tDfR[2 * MAX_RLP];
	RLP tDfA[2 * MAX_RLP];
	RLP tDfB[2 * MAX_RLP];

	/*--- start ---*/

	/* read input */
	while(scanf("%d", &nWidth) == 1) {

		/* print output */
		printf("%d\n", nWidth);

		if(nWidth == 0) {
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
			tIn[nPair].nLen = nL;

			/* increment RLP array index */
			++nPair;
		}

		/* calc diffs */

		/* to the right */
		for(i = 0; i < nPair - 1; i++) {
			tDfR[i * 2].nVal = 0;
			tDfR[i * 2].nLen = tIn[i].nLen - 1; /* possibly 0 len */
			tDfR[i * 2 + 1].nVal = abs(tIn[i + 1].nVal - tIn[i].nVal);
			tDfR[i * 2 + 1].nLen = 1;
		}
		tDfR[(nPair - 1) * 2].nVal = 0;
		tDfR[(nPair - 1) * 2].nLen = tIn[i].nLen;
		tDfR[(nPair - 1) * 2 + 1].nVal = 0; /* redundant */
		tDfR[(nPair - 1) * 2 + 1].nLen = 0; /* redundant */

		/* to the left */
		tDfL[0].nVal = 0;
		tDfL[0].nLen = tIn[i].nLen;
		tDfL[1].nVal = 0; /* redundant */
		tDfL[1].nLen = 0; /* ditto */
		for(i = 1; i < nPair; i++) {
			tDfL[i * 2].nVal = abs(tIn[i - 1].nVal - tIn[i].nVal);
			tDfL[i * 2].nLen = 1;
			tDfL[i * 2 + 1].nVal = 0;
			tDfL[i * 2 + 1].nLen = tIn[i].nLen - 1; /* possibly zero */
		}

		/* to the above */


		/* to the below */



	}

	
	return 0;
}