/* POJ 1010 */

#include <stdio.h>
#include <stdlib.h>

/* maximum number of types */
#define MAX_TYPES	25

/* stamps */
typedef struct Stamps_t {
	/* nominal value */
	int nVal;
	/* number of types of the same value */
	int nTyp;
} Stamps;

/* qsort compare function: by struct member (nVal) */
int compStampVal(const void* pa, const void* pb) {
	/* simple integer comparison */
	return (((Stamps*)pa)->nVal - ((Stamps*)pb)->nVal);
}

int main() {
    /* iterators and temporary */
    int i;
    int nN;
    /* array: available stamps */
    Stamps tSt[MAX_TYPES];
    /* the number of stamps */
    int nTotalTyp;
    /* total value when each different stamp added */
    int nTotalVal; 

    /*--- start ---*/

    /* reset the total number of types */
    nTotalTyp = 0;
    /* read from stdin */
    while(scanf("%d", &nN) != EOF) {
        /* start of the first line of input */
        /* store the first element into the array */

        tSt[nTotalTyp].nVal = nN;
        ++nTotalTyp;

        /* read the rest of the first line */
        while(scanf("%d", &nN) == 1) {
            if(nN == 0) {
                /* end of the first line */
                break;
            }

            /* store an element into the array */
            tSt[nTotalTyp].nVal = nN;
            ++nTotalTyp;
        }
        /* first line has been read */

        /* sort the stamp array */
        qsort(tSt, nTotalTyp, sizeof(Stamps), compStampVal);





        /* calculate total value when each different stamp is added */
        nTotalVal = 0;
        for(i = 0; i < nTotalTyp; i++) {
            nTotalVal += tSt[i].nVal;
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
            if(nN == nTotalVal) {
                /* exactly match for one each of all stamps */
                /* job done: simple answer */
                printf("%d (%d):", nN, nTotalTyp);
                for(i = 0; i < nTotalTyp; i++) {
                    printf(" %d", tSt[i].nVal);
                }
                printf("\n");
            } else if(nN > nTotalVal) {

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
        nTotalTyp = 0;
    }

    return 0;
}