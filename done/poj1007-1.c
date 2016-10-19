/* POJ 1007 */
/* using 2D array only */

#include <stdio.h>
#include <stdlib.h>

int cmpArray(const void *pa, const void *pb) {
    const int *a = (int*)*(int*)pa;
    const int *b = (int*)*(int*)pb;
    return a[0] - b[0];
}

int main() {
    /* iterator */
    int i, j, k;
    /* length of string */
    int iLen;
    /* number of strings */
    int iRow;
    /* number of inversions */
    int** iInv;
    /* pointer to the char table */
    char** cTab;

    /* read parameters */
    scanf("%d %d", &iLen, &iRow);

    /* allocate memory for the char table */
    /* first, array of pointers to strings */
    cTab = (char**)malloc(sizeof(char*) * iRow);
    /* for count of inversions, count[0] and index[1] */
    iInv = (int**)malloc(sizeof(int*) * iRow);

    /* iterating rows */
    for(i=0; i<iRow; i++) {
        /* second, allocate for each row of string, with terminator */
        cTab[i] = (char*)malloc(sizeof(char) * (iLen+1));
        /* for the count array with count[0], index[1] */
        iInv[i] = (int*)malloc(sizeof(int) * 2);
        /* reset inversion counter[0] */
        iInv[i][0] = 0;
        /* store index[1] in the counter array */
        iInv[i][1] = i;
        /* scan the row */
        scanf("%s", cTab[i]);

        /* computing count of inversions */
        for(j=0; j<iLen-1; j++) {
            for(k=j+1; k<iLen; k++) {
                if(cTab[i][j] > cTab[i][k]) {
                    ++iInv[i][0];
                }
            }
        }
    }

    /* sorting the row array */
    qsort(iInv, iRow, sizeof(int*), cmpArray);

    /* print output */
    for(i=0; i<iRow; i++) {
        printf("%s\n", cTab[iInv[i][1]]);
    }

    return 0;
}