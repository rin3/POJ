/* POJ 1004 */

#include <stdio.h>

#define NMONTH      12

int main() {
    /* iterator */
    int i;

    /* balance each month */
    float fBal;
    /* total & average balances */
    float fTA = 0;

    /* reading and adding up lines */
    for(i = 0; i < NMONTH; i++) {
        scanf("%f", &fBal);
        fTA += fBal;
    }

    /* calc average */
    fTA /= NMONTH;

    /* output */
    printf("$%.2f\n", fTA);

    return 0;
}