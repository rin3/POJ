/* POJ 1010 */

#include <stdio.h>
#include <stdlib.h>

#define MAX_STAMPS      25

/* compare function for qsort */
int compInt(const void* pa, const void* pb) {
	/* simple integer comparison */
	return (*(int*)pa - *(int*)pb);
}

int main() {
    /* iterators and temporary */
    int i;
    int nN;
    /* array: available stamps */
    int nStamps[MAX_STAMPS];
    /* the number of stamps */
    int nNumStamps;
    /* total value when each different stamp added */
    int nTotalEa; 

    /*--- start ---*/

    /* reset the number of stamps */
    nNumStamps = 0;
    /* read from stdin */
    while(scanf("%d", &nN) != EOF) {
        /* start of the first line of input */
        /* store the first element into the array */

        nStamps[nNumStamps] = nN;
        ++nNumStamps;

        /* read the rest of the first line */
        while(scanf("%d", &nN) == 1) {
            if(nN == 0) {
                /* end of the first line */
                break;
            }

            /* store an element into the array */
            nStamps[nNumStamps] = nN;
            ++nNumStamps;
        }
        /* first line has been read */

        /* sort the stamp array */
        qsort(nStamps, nNumStamps, sizeof(int), compInt);

        /* calculate total value when each different stamp is added */
        nTotalEa = 0;
        for(i = 0; i < nNumStamps; i++) {
            nTotalEa += nStamps[i];
        }

        /* read the second line */
        while(scanf("%d", &nN) == 1) {
            if(nN == 0) {
                /* end of the second line */
                break;
            }
            /* nN = value of customer's request */

            /*--- solution for each customer ---*/

            /* can all types included? */
            if(nN == nTotalEa) {
                /* exactly match for one each of all stamps */
                /* job done: simple answer */
                printf("%d (%d):", nN, nNumStamps);
                for(i = 0; i < nNumStamps; i++) {
                    printf(" %d", nStamps[i]);
                }
                printf("\n");
            } else if(nN > nTotalEa) {

            } else {
                /* nN < nTotalEa */
            }

/* now solve it 
- max number of different types 
- if tie, fewest total stamps is best
- if still tie, set with highest single value stamp is best
- if still tie, print 'tie'

print
- total value 7
- number of different types offered 3
- : breakdown
- if none print none */




        }

        /* a set of problem has been solved */
        /* reset variables */
        nNumStamps = 0;
    }

    return 0;
}