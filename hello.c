#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
	/* iterators */
	int i, j, k;
	/* number of row */
	int iRN;
	/* row string */
	char cR[16];
	/* number only string */
	char cRn[8];
	/* number array */
	int iNum[NMAX];

	/* read number of row */
	scanf("%d", &iRN);

	/* initialization */
	for(i=0; i<NMAX; i++) {
		iNum[i] = 0;
	}

	/* iterating rows */
	for(i=0; i<iRN; i++) {
		/* cRn index */
		k=0;

		/* read row */
		scanf("%s", &cR);

		/* translate into a simple string number */
		for(j=0; j<strlen(cR); j++) {
			if(cR[j] == '-') {
				/* skip hyphen */
				continue;
			} else {
				if('A' <= cR[j] && cR[j] <= 'Z') {
					/* converting 'A' to '2' etc. */
					cRn[k] = alpha2num(cR[j]);
				} else {
					/* if not, pure numbers */
					cRn[k] = cR[j];
				}
				/* increment cRn index */
				k++;
			}	
		}
		/* terminate cRn */
		cRn[k] = 0;

		/* increment relevant element in the number array */
		++iNum[atoi(cRn)];


	}


	return 0;
}