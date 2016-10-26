/* POJ 1009 */

#include <stdio.h>
/*#include <stdlib.h>*/

#define TRUE    1
#define FALSE   0

/* type for run length pairs */
typedef struct RLP_Input_t {
	int nVal;
	int nLen;
} RLP_Input;

typedef struct RLP_Diff_t {
	int nVal;
	int nLen;
	/* direction */
	int nDir;
} RLP_Diff;

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
	RLP_Input tIn[1000];
	/* differential array */
	RLP_Diff tDif[2000];

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





	}

	
	return 0;
}