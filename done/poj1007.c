/* POJ 1007 */
/* using struct */

#include <stdio.h>
#include <stdlib.h>

typedef struct DNA_t {
    int iInv;
    char* strDNA;
} DNA;

/* qsort comparator function */
/* comparing iInv */
int cmpInv(const void *pa, const void *pb) {
    return ((DNA*)pa)->iInv - ((DNA*)pb)->iInv;
}

int main() {
    /* iterator */
    int i, j, k;
    /* length of string */
    int iLen;
    /* number of strings */
    int iRow;
    /* the DNA table */
    DNA* dnaTab;
    /* read parameters */
    scanf("%d %d", &iLen, &iRow);
    /* allocate memory for the DNA struct */
    dnaTab = (DNA*)malloc(sizeof(DNA) * iRow);

    /* iterating rows */
    for(i=0; i<iRow; i++) {
        /* reset inversion counter */
        dnaTab[i].iInv = 0;
        /* allocate memory for each DNA, with terminator */
        dnaTab[i].strDNA = (char*)malloc(sizeof(char) * (iLen+1));
        /* scan the row */
        scanf("%s", dnaTab[i].strDNA);

        /* computing count of inversions */
        for(j=0; j<iLen-1; j++) {
            for(k=j+1; k<iLen; k++) {
                if(dnaTab[i].strDNA[j] > dnaTab[i].strDNA[k]) {
                    ++dnaTab[i].iInv;
                }
            }
        }
    }

    /* sorting the row array */
    qsort(dnaTab, iRow, sizeof(DNA), cmpInv);

    /* print output */
    for(i=0; i<iRow; i++) {
        printf("%s\n", dnaTab[i].strDNA);
    }

    return 0;
}