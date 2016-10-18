#include <stdio.h>

int main() {
    int i;
    char c;

    scanf("%d", &i);

    while((c = getchar()) != EOF) {
printf("PRT %d\n", c);
    }

    return 0;
}