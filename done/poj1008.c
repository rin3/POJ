/* POJ 1008 */

#include <stdio.h>
#include <string.h>

/* length of Haab month */
#define LEN_HAAB_MON        20
/* number of Haab month */
#define NUM_HAAB_MON        19
/* length of TZolkin period */
#define LEN_TZOLKIN_PERIOD  20
/* number of Tzolkin period */
#define NUM_TZOLKIN_PERIOD  13
/* length of Tzolkin year */
#define LEN_TZOLKIN_YEAR    260

/* name of the month */
const char strHaab[19][10] = { "pop", "no", "zip", "zotz", "tzec" \
                        , "xul", "yoxkin", "mol", "chen", "yax" \
                        , "zac", "ceh", "mac", "kankin", "muan" \
                        , "pax", "koyab", "cumhu", "uayet" }; 

/* name of the day */
const char strTzolkin[20][10] = { "imix", "ik", "akbal", "kan", "chicchan" \
                        , "cimi", "manik", "lamat", "muluk", "ok" \
                        , "chuen", "eb", "ben", "ix", "mem" \
                        , "cib", "caban", "eznab", "canac", "ahau" };

/* find the order of Haab month */
int findHaabMon(char* strIn) {
    int i;

    /* find matching names */
    for(i=0; i<NUM_HAAB_MON; i++) {
        if(strcmp(strIn, strHaab[i]) == 0) {
            /* match found */
            return i;
        }
    }

    /* in case of error */
    return -1;
}

int main() {
    /* iterators */
    int i;
    /* number of items */
    int nI;
    /* total days since the beginning of the world */
    int nTDays;
    /* Haab date */
    int nHDay;
    char strHMon[10];
    int nHYear;
    /* Tzolkin date */
    int nTYear;
    /* Tzolkin days since the beginning of the current year */
    int nTDaySinceThisYear;
    
    /* read number of items */
    scanf("%d", &nI);

    /* print number of items */
    printf("%d\n", nI);

    /* iterating items */
    for(i=0; i<nI; i++) {
        /* read a stdin line */
        scanf("%d. %s %d", &nHDay, strHMon, &nHYear);

        /* compute total days */
        nTDays = nHDay + findHaabMon(strHMon) * LEN_HAAB_MON + nHYear * 365;

        /* translate into Tzolkin date */
        nTYear = (int)(nTDays / LEN_TZOLKIN_YEAR);
        nTDaySinceThisYear = nTDays % LEN_TZOLKIN_YEAR;

        /* print output for each item */
        printf("%d %s %d\n", nTDaySinceThisYear % NUM_TZOLKIN_PERIOD + 1, \
            strTzolkin[nTDaySinceThisYear % LEN_TZOLKIN_PERIOD], \
            nTYear);
    }

    return 0;
}