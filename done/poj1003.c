#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* calculate length of N hangover */
float calcLen(int n) {
	float fResult = 0;
	int i;

	for(i = 0; i < n; i++) {
		fResult += (float)1/(i+2);
	}
	return fResult;
}

int main() {
	/* input number string */
	char strLn[5];
	/* number of cards */
	int iC;

	while(scanf("%s", strLn) == 1) {
		if(strcmp(strLn, "0.00") == 0) {
			/* end of input */
			break;
		} else {
			/* initialise n of cards */
			iC = 1;
			/* endless loop */
			while(1) {
				/* compare numbers in float */
				if(calcLen(iC) >= atof(strLn)) {
					/* found answer */
					printf("%d card(s)\n", iC);
					/* go to next line */
					break;
				} else {
					/* increment n of cards */
					++iC;
				}
			}
		}
	}
	return 0;
}