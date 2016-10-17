#include <stdio.h>
#include <math.h>

int main() {
	float fR, fAns;
	int iN, iAns;
	char strAns[100];

	while(scanf("%f%d", &fR, &iN) == 2) {
		fAns = 1;
		
		for(int i=0; i<iN; i++) {
			fAns = fAns * fR;
		}
		iAns = (int)fAns;

		if(iAns == fAns) {
			printf("%d\n", iAns);
		} else if(fAns < 1) {
				sprintf(strAns, "%f", fAns);
				printf("%s\n", strAns+1);
		} else {
				printf("%f\n", fAns);
		}
	}
	
  return 0;
}