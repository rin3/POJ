/* POJ 1009

 Three rows for iteration
           |<----image----->|
         0  1  2  3  4       nWidth+1
 cR[2]  [=][.][.][.][ ]...[ ][=]
 cR[1]  [=][.][*][.][ ]...[ ][=]
 cR[0]  [=][.][.][.][ ]...[ ][=]
 [=] is dummy column for padding
 */

#include <stdio.h>
#include <stdlib.h>

#define TRUE    1
#define FALSE   0

/* shifting up the rows of the image matrix */
/* cR[2] <= cR[1], cR[1] <= cR[0] */
void shiftRows(int _nWidth, unsigned char** _cR) {
    int i, j;
    for(i=1; i>=0; i--) {
        /* including padding columns */
        for(j=0; j<=_nWidth+1; j++) {
            _cR[i+1][j] = _cR[i][j];
        }
    }
    return;
}

/* compute the edge value from three rows */
void compEdge(int _nWidth, unsigned char** _cR, unsigned char* _cE) {
    int i, j, k;
    /* temporary */
    int nDif;

    /* over the width */
    for(i=1; i<=_nWidth; i++) {
        /* reset max value */
        _cE[i-1] = 0;
        /* left, center, right */
        for(j=-1; j<=1; j++) {
            /* above[2], current[1], below[0] */
            for(k=0; k<=2; k++) {
                nDif = abs(_cR[k][i+j] - _cR[1][i]);
                if(nDif > _cE[i-1]) {
                    _cE[i-1] = nDif;
                }
            }
        }
        /* found edge for a column */
    }
    /* done for all width */
    return;
}

void _printRow(int _nWidth, unsigned char** _cR) {
    int i, j;
    for(i=0; i<=2; i++) {
        for(j=0; j<=_nWidth+1; j++) {
            printf("%03d ", _cR[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void _printEdge(int _nWidth, unsigned char* _cE) {
    int i;
    printf("    ");
    for(i=0; i<_nWidth; i++) {
        printf("%03d ", _cE[i]);
    }
    printf("\n\n");
}

void rowComplete(int _nWidth, unsigned char** _cR, unsigned char* _cE, int* pnRC) {
    /* padding both sides of the 0th(new) image row */
    _cR[0][0] = _cR[0][1];
    _cR[0][_nWidth+1] = _cR[0][_nWidth];

printf("rowComplete=%d\n", *pnRC);
    /* if it's the very first row */
    if(*pnRC == 1) {
        /* yes, the 1st row */
        /* shift twice to fill the matrix, but no computation */
        shiftRows(_nWidth, _cR);
        shiftRows(_nWidth, _cR);
_printRow(_nWidth, _cR);
    } else if(*pnRC >= 2) {
        /* do computation */
_printRow(_nWidth, _cR);
        compEdge(_nWidth, _cR, _cE);
        /* shifting up the rows for next iteration */
        shiftRows(_nWidth, _cR);
_printEdge(_nWidth, _cE);
    }

/* matrix processing */

    return;
}

void printRow(int _nWidth, unsigned char* _cE, int* pnRun, unsigned char* pcVal, int* pnSkip) {
    int i;

    /* iterate over width */
    for(i=0; i<_nWidth; i++) {
        if(*pnRun == 0) {
            /* the beginning of the edge image */
            *pcVal = _cE[i];
            *pnRun = 1;
        } else {
            /* *pnRun > 0, ie. not the beginning */
            if(_cE[i] == *pcVal) {
                /* this edge pixel is the same as the end of the previous row */
                /* increment the number of run */
                ++(*pnRun);
            } else {
                /* value different */
                /* see if super long run length */
                if(*pnSkip > 0) {
                    /* add back skip length */
                    *pnRun += *pnSkip;
                }
                /* print an output line */
                printf("%d %d\n", *pcVal, *pnRun);
                /* set new pair */
                *pcVal = _cE[i];
                *pnRun = 1;
            }
        }
    }

}

int main() {
    /* iterators */
    int i;
    /* image width */
    int nWidth;
    /* three rows */
    unsigned char* cR[3];
    /* edge row */
    unsigned char* cE;
    /* RLE pixel value */
    int nV;
    /* RLE run length */
    int nL;
    /* row index to fill */
    int nIdx2Fil;
    /* row count per single image */
    int nRC;
    /* skipped super long run length */
    int nSkip;
    /* last run length of the edge data */
    int nRun;
    /* last pixel value of the edge data */
    unsigned char cVal;

    /* read width */
    while(scanf("%d", &nWidth) == 1) {
        /* see if end of input */
        if(nWidth == 0) {
            break;
        }

        /* processing an image */

        /* allocating memory */
        /* - for image rows */
        for(i=0; i<=2; i++) {
            /* including padding lines both sides */
            cR[i] = (unsigned char*)malloc(sizeof(unsigned char) * (nWidth + 2));
        }
        /* - for edge row */
        cE = (unsigned char*)malloc(sizeof(unsigned char) * nWidth);

        /* reset row count */
        nRC = 0;

        /* reset index to fill in a row */
        nIdx2Fil = 0;

        /* initialised as zero for marking the beginning of edge output */
        nRun = 0;

        /* reset skip length for super long run length */
        nSkip = 0;

        /* reading a pair of RLE element */
        while(scanf("%d %d", &nV, &nL)) {
            if(nV == 0 && nL == 0) {
                /* was end of image */
                /* shift a row and compute */
                shiftRows(nWidth, cR);
_printRow(nWidth, cR);
                compEdge(nWidth, cR, cE);
_printEdge(nWidth, cE);

/* do something */

                break;
            }

            /* dealing with super long run length */
            if((int)(nL / nWidth) > 3) {
                /* if run length is more than 4 times the width */                
                /* shorten run length and set skip length */
                nSkip = (int)(nL / nWidth) - 3;
                nL -= nSkip * nWidth;
            }

            /* do job until run length is fully used */ 
            while(nL) {
                /* branching on the run length to the remainder */
                if(nWidth > nIdx2Fil + nL) {
                    /* less than the width of the row */
                    /* filling only */
                    for(i=0; i<nL; i++) {
                        cR[0][1 + nIdx2Fil + i] = (unsigned char)nV;
                    }
                    /* move the index */
                    nIdx2Fil += nL;
                    /* a single RLE pair is done */
                    nL = 0;
                } else if(nWidth == nIdx2Fil + nL) {
                    /* just the width of the row */
                    /* fill the remainder to the row end */
                    for(i=0; i<nL; i++) {
                        cR[0][1 + nIdx2Fil + i] = (unsigned char)nV;
                    }
                    /* reset the index */
                    nIdx2Fil = 0;
                    /* a single RLE pair is done */
                    nL = 0;
                    /* jump to row processing */
                    ++nRC;
                    rowComplete(nWidth, cR, cE, &nRC);
                } else {
                    /* nWidth < nIdx2Fil + nL */
                    /* overflow */
                    /* fill the remainder to the row end */
                    for(i=nIdx2Fil; i<nWidth; i++) {
                        cR[0][1 + i] = (unsigned char)nV;
                    }
                    /* decrement the run length */
                    nL -= (nWidth - nIdx2Fil);
                    /* reset the index */
                    nIdx2Fil = 0;
                    /* jump to row processing */
                    ++nRC;
                    rowComplete(nWidth, cR, cE, &nRC);
                }
            }
        }
        /* a single image is done */
        /* freeing memory */
        for(i=0; i<=2; i++) {
            free(cR[i]);
        }
        free(cE);
    }

    return 0;
}