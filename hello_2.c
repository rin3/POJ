#include <stdio.h>

#define SLEN		256

int findDecimalPoint(char* sArg) {
	int i=0;
	while(sArg[i++] != 0) {
		while(sArg[i++] != '.');
		return --i;
	}

}

char* multString(char* sA, char* sB) {
	return "asdf";
}

int main() {
	char sR[SLEN];
	int iN;

	while(scanf("%s%d", &sR, &iN) == 2) {

		printf("ANSW %d\n", findDecimalPoint(sR));

/*		if(iAns == fAns) {
			printf("%d\n", iAns);
		} else if(fAns < 1) {
				sprintf(strAns, "%f", fAns);
				printf("%s\n", strAns+1);
		} else {
				printf("%f\n", fAns);
		} */
		
		
	}
	
  return 0;
}