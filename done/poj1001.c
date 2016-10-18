#include <stdio.h>
#include <string.h>

#define TRUE		1
#define FALSE		0
#define SLEN		256

int findDecimalPoint(char* sArg) {
	int i=0;
	while(sArg[i++] != '.');
	return --i;
}

void removeTrailingZerosKeepDP(char* sArg) {
	int i=strlen(sArg)-1;

	while(i>=1) {
		if(sArg[i] != '0') {
			return;
		} else if(sArg[i-1] == '.') {
			return;
		} else {
			sArg[i] = 0;	// set terminator
			i--;
		}
	}
}

void removeLeadingZerosKeepDP(char* sArg) {
	int i=0;	// number of leading zeros
	int iLeadExist = FALSE;
	int j;

	// find number of leading zeros
	while(i < strlen(sArg)) {
		if(sArg[i] != '0') {
			break;
		} else {
			iLeadExist = TRUE;
			i++;
		}
	}

	// shift characters
	if(iLeadExist == TRUE) {
		for(j=0; j<strlen(sArg)-i+1; j++) {
			sArg[j] = sArg[j+i];
		}
	}

}

void multString(char* sA, char* sB, char* sX) {
	int iDPA, iDPB;
	int iLenA, iLenB;
	char sAA[SLEN], sBB[SLEN], sXX[SLEN];
	int iXX[SLEN];
	int i, j, k;

	// index of decimal point
	iDPA = findDecimalPoint(sA);
	iDPB = findDecimalPoint(sB);
	// length of the input strings
	iLenA = strlen(sA);
	iLenB = strlen(sB);

	// make strings w/o d.p.
	strcpy(sAA, sA);
	strcpy(sBB, sB);

	for(i=iDPA+1; i<iLenA; i++) {
		sAA[i-1] = sAA[i];
	}
	sAA[iLenA-1] = 0;	// terminator

	for(i=iDPB+1; i<iLenB; i++) {
		sBB[i-1] = sBB[i];
	}
	sBB[iLenB-1] = 0;	// terminator

	// clearing output string buffer
	for(i=0; i<SLEN; i++) {
		iXX[i] = 0;
		sXX[i] = 0;
	}

	// string multiplication
	for(i=iLenA-1; i>0; i--) {
		for(j=iLenB-1; j>0; j--) {
			iXX[iLenA+iLenB-2-i-j] += (sBB[j-1]-'0') * (sAA[i-1]-'0');
		}
	}
	// raising digits
	for(k=0; k<iLenA+iLenB-3; k++) {
		if(iXX[k] > 99) {
			iXX[k+2] += (int)(iXX[k]/100);
			iXX[k] -= (int)(iXX[k]/100)*100;
		}
		if(iXX[k] > 9) {
			iXX[k+1] += (int)(iXX[k]/10);
			iXX[k] -= (int)(iXX[k]/10)*10;
		}
	}
	// now elements as character number
	for(k=0; k<iLenA+iLenB-1; k++) {
		sXX[k] = iXX[k];
		sXX[k] += '0';
	}

	// setting decimal point
	for(k=iLenA+iLenB-1; k>iLenA+iLenB-iDPA-iDPB-2; k--) {
		sXX[k] = sXX[k-1];
	}
	sXX[iLenA+iLenB-iDPA-iDPB-2] = '.';

	// reverse string
	for(i=0; i<strlen(sXX); i++) {
		sX[i] = sXX[strlen(sXX)-1-i];
	}
	sX[strlen(sXX)] = 0;

	// remove trailing zeros
	removeTrailingZerosKeepDP(sX);
	removeLeadingZerosKeepDP(sX);

	return;
}

int main() {
	// input
	char sR[SLEN];
	int iN;
	int i;

	// buffer
	char sBuf[SLEN], sBuf2[SLEN];

	while(scanf("%s%d", &sR, &iN) == 2) {
		strcpy(sBuf, "1.0");

		for(i=0; i<iN; i++) {
			strcpy(sBuf2, sBuf);
			multString(sBuf2, sR, sBuf);
		}

		// check integer result
		if(sBuf[strlen(sBuf)-1] == '0' && sBuf[strlen(sBuf)-2] == '.') {
			sBuf[strlen(sBuf)-2] = 0;	// set terminator
		}

		// display result on output
		printf("%s\n", sBuf);
	}
	return 0;
}