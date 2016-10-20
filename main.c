/* POJ 1009

 Three rows for iteration
 cR[0]  [ ][.][.][.][ ][ ]
 cR[1]  [ ][.][*][.][ ][ ]
 cR[2]  [ ][.][.][.][ ][ ]
 */

#include <stdio.h>
#include <stdlib.h>

/* compute the edge value from three rows */
void compEdge(int _nWidth, char** _cR, char* _cE) {

    for(i=1; i<_nWidth-1; i++) {

    }

    return;
}

int main() {
    /* iterators */
    int i;
    /* image width */
    int nWidth;
    /* three rows */
    char* cR[3];
    /* edge row */
    char* cE;
    /* RLE pixel value */
    char cV;
    /* RLE run length */
    int nL;

    /* read width */
    while(scanf("%d", &nWidth) == 1) {
        /* see if end of input */
        if(nWidth == 0) {
            break;
        }

        /* processing an image */

        /* allocating memory */
        /* - for image rows */
        for(i=0; i<2; i++) {
            /* including padding lines both sides */
            cR[i] = (char*)malloc(sizeof(char) * (nWidth + 2);
        }
        /* - for edge row */
        cE = (char*)malloc(sizeof(char) * nWidth);

        /* reading a pair of RLE element */
        while(scanf("%d %d", (int*)&cV, &nL)) {
            if(cV == 0 && nL == 0) {
                /* was end of image */

                break;
            }

        }

    }

    /* freeing memory */
    for(i=0; i<2; i++) {
        free(cR[i]);
    }
    free(cE);

    return 0;
}