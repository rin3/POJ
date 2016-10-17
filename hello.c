#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* max number of tel numbers */
#define NMAX	10000000

/* ascii table */
						/* @  A  B  C  D  E  F  G  H  I  J  K  L  M */
const char cTable[27] = { 0, '2', '2', '2', '3', '3', '3', '4', '4', '4', '5', '5', '5', '6', \
						/* N  O  P  Q  R  S  T  U  V  W  X  Y  Z */
						'6', '6', '7', 0, '7', '7', '8', '8', '8', '9', '9', '9', 0 };

/* number struct */
typedef struct NumArrays {
	int iTel;
	int iCount;
} NumArray;

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
	/* number struct */
	NumArray numArray[NMAX];

	/* read number of row */
	scanf("%d", &iRN);

	/* initialization */
	for(i=0; i<NMAX; i++) {
		numArray[i].iTel = i;
		numArray[i].iCount = 0;
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
		++numArray[atoi(cRn)].iCount;


	}


	return 0;
}