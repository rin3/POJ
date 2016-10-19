/* POJ 1006 */

#include <stdio.h>

#define PERIOD_P    23
#define PERIOD_E    28
#define PERIOD_I    33
#define BIG_PERIOD  PERIOD_P * PERIOD_E * PERIOD_I
#define BIT_P       1
#define BIT_E       2
#define BIT_I       4
#define BIT_ALL     7

/* array of whole cycle */
char cCy[BIG_PERIOD];

void fillWBits(int iPeakGiven, int iPeriod, char cBit) {
    /* iterator */
    int i;

    for(i= iPeakGiven % iPeriod; i<BIG_PERIOD; i+=iPeriod) {
        cCy[i] += cBit;
    }
    return;
}

int main() {
    /* iterator */
    int i;
    /* expected peaks */
    int iP, iE, iI;
    /* current date */
    int iCur;
    /* the triple peak */
    int iTriple;
    /* the number of cases */
    int iNum = 0;

        /* iterating lines */
    while(scanf("%d %d %d %d", &iP, &iE, &iI, &iCur) == 4) {
        /* check end of input */
        if(iP==-1 && iE==-1 && iI==-1 && iCur==-1) {
            break;
        }

        /* increment the number of cases */
        ++iNum;

        /* clean up array of cycle */
        for(i=0; i<BIG_PERIOD; i++) {
            cCy[i] = 0;
        }

        /* calculate modulus over whole array */
        fillWBits(iP, PERIOD_P, BIT_P);
        fillWBits(iE, PERIOD_E, BIT_E);
        fillWBits(iI, PERIOD_I, BIT_I);

        /* find the triple peak */
        for(i=0; i<BIG_PERIOD; i++) {
            if(cCy[i] == BIT_ALL) {
                iTriple = i;
                break;
            }
        }

        /* adjustment per problem request */
        if(iTriple <= iCur) {
            iTriple += BIG_PERIOD;
        }

        /* print result */
        printf("Case %d: the next triple peak occurs in %d days.\n", iNum, iTriple-iCur);
    }

    return 0;
}