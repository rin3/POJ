#include <stdio.h>
#include <stdlib.h>

void routeA(char** _cTT) {
printf("in route\n");
_cTT[1][1] = 90;
printf("%d \n", _cTT[1][1]);
    return;
}


int main() {
    int i;
    char* cTT[3];

    for(i=0; i<3; i++) {
        cTT[i] = (char*)malloc(sizeof(char) * 10);
    }
    routeA(cTT);

    return 0;
}