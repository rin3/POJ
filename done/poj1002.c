#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE	1
#define FALSE	0

/* max number of tel numbers */
#define NMAX	100000

/* ascii table */
						/* @  A  B  C  D  E  F  G  H  I  J  K  L  M */
const char cTable[27] = { 0, '2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', \
						/* N  O  P  Q  R  S  T  U  V  W  X  Y  Z */
						'6', '6', '7', 0, '7', '7', '8', '8', '8', '9', '9', '9', 0 };

char alpha2num(char cIn) {
	return cTable[cIn - '@'];
}

int cmpNumArray(const void *a, const void *b) {
	return *(int*)a - *(int*)b;
}

void printNoDupl() {
	printf("No duplicates.\n");
	return;
}

void translate2String(char* str, int n) {
	int i;
	/* convert int to string */
	sprintf(str, "%07d", n);
	/* insert hyphen */
	for(i=strlen(str); i>=3; i--) {
		str[i+1] = str[i];
	}
	str[3] = '-';

	return;
}

void printReport(int iTel, int iDup) {
	/* string buffer */
	char strTel[9];

	translate2String(strTel, iTel);
	printf("%s %d\n", strTel, iDup+1);					

	return;
}

int main() {
	/* iterators */
	int i = 0;
	int j = 0;
	/* number of row */
	int iRN;
	/* stdin iterator */
	char c;
	/* number only string */
	char cRn[8];
	/* number struct */
	int numArray[NMAX];
	/* if duplicates exist at all? */
	int iDupFlag = FALSE;
	/* number of duplicates for each number */
	int iDup = 0;

	/* read number of row */
	scanf("%d", &iRN);
	/* throw away an LF after the 1st line */
	c = getchar();

	/* iterating rows */
	while((c = getchar()) != EOF) {
		if(c == '\n') {
			/* found line feed */
			/* terminate cRn string */
			cRn[i] = 0;
			/* store in the num array */
			numArray[j] = atoi(cRn);
			/* reset cRn index */
			i = 0;
			/* increment numArray index */
			j++;
		} else if(c == '-') {
			/* skip hyphen */
			continue;
		} else {
			if('A' <= c && c <= 'Z') {
				/* converting 'A' to '2' etc. */
				cRn[i] = alpha2num(c);
			} else {
				/* if not, pure numbers */
				cRn[i] = c;
			}
			/* increment cRn index */
			i++;
		}
	}
	/* reached EOF, now do the last line */
	/* terminate cRn string */
	cRn[i] = 0;
	/* store in the num array */
	numArray[j] = atoi(cRn);

	/* sort number array */
	qsort(numArray, iRN, sizeof(int), cmpNumArray);

	/* show result */
	if(iRN == 1) {
		/* when iRN is only one! */
		printNoDupl();
		return 0;
	} else {
		/* iRN is more than one */
		for(i=1; i<iRN; i++) {
			if(numArray[i-1] == numArray[i]) {
				/* if the num is the same as the one before */
				/* set duplicate as existed */
				iDupFlag = TRUE;
				/* increment number of duplicates */
				++iDup;
				if(i==iRN-1) {
					/* last bit */
					printReport(numArray[i], iDup);
				}
			} else {
				/* the num is different than the previous */
				if(iDup != 0) {
					/* was duplicates, print */
					printReport(numArray[i-1], iDup);
					/* reset iDup */
					iDup = 0;
				} else {
					/* was no duplicates */
					/* do nothing */
				}
			}
		}
		/* if no duplicates */
		if(iDupFlag == 0) {
			printNoDupl();
		}
	}
	return 0;
}