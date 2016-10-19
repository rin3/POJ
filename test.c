#include <stdio.h>

int nar[4][2] = { {1,2},{3,4},{5,6},{7,8} };


int main() {
    int i,j;

    for(i=0; i<4; i++) {
        for(j=0; j<2; j++) {
            printf("nar[%d][%d] = %d\n", i,j, nar[i][j]);
        }
    }

    printf("nar = %d\n", nar);
    printf("nar[0] = %d\n", nar[0]);
    printf("*nar[0] = %d\n", *nar[0]);
    printf("nar[0][0] = %d\n", nar[0][0]);
    printf("nar[1] = %d\n", nar[1]);
    printf("*nar[1] = %d\n", *nar[1]);
    printf("nar[1][0] = %d\n", nar[1][0]);
    

    return 0;
}