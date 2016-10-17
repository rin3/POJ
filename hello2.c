#include <stdio.h>
#include <string.h>

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

	/* read number of row */
	scanf("%d", &iRN);
printf("%d wors\n", iRN);

	/* iterating rows */
	for(i=0; i<iRN; i++) {
		printf("%d times iteration\n", i);
		/* cRn index */
		k=0;

		/* read row */
		scanf("%s", &cR);
		printf("%d %s", i, cR);

		/* terminate cRn */
		cRn[k] = 0;

		printf(" --> %s\n", cRn);

	}

	return 0;
}