/* POJ 1009

 Three rows for iteration
		   |<----image----->|
            nIX
         0  1  2  3  4       nWidth+1
     0  [=][.][.][.][ ]...[ ][=]
 nIY 1  [=][.][*][.][ ]...[ ][=]
     2  [=][.][.][.][ ]...[ ][=]
 [=] is dummy column for padding
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

/* run length encoding pair */
typedef struct RLEP_t {
	int nVal;
	int nRun;
} RLEP;

int getVal(int X, int Y) {

}

int main() {
	/* iterators */
	int i;
	/* image width and height */
	int nWidth, nHeight;
	/* pixel value, input iamge */
	int nV;
	/* run length, input image */
	int nL;
	/* RLE pairs array */
	RLEP RLP[1000];
	/* number of RLE pairs */
	int nP;

	/* coords for input/output images *
	int nIX, nIY;
	int nOX, nOY;
	* keeping the last heads *
	int nPIX, nPIY;
	int nPOX, nPOY;
	* or new heads *
	int nNIX, nNIY;
	int nNOX, nNOY;*/

	/* read input */
	while(scanf("%d", &nWidth) == 1) {

		if(nWidth == 0) {
			/* end of input */
			break;
		}

		/* processing of an image */

		/* reset the number of RLE pairs */
		nP = 0;

		/* read RLE pairs */
		while(scanf("%d %d", &nV, &nL) == 2) {

			if(nV == 0 && nL == 0) {
				/* end of an image */
				break;
			}

			/* fill RLE pair array */
			RLP[nP].nVal = nV;
			RLP[nP].nRun = nL;

			/* increment RLE pair index */
			++nP;
		}
		/* an image was read */

		/* compute image height */
		nHeight = 0;
		for(i=0; i<nP; i++) {
			nHeight += RLP[i].nRun;
		}
		nHeight /= nWidth;




	}

	return 0;
}