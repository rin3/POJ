/* POJ 1005 */

#include <stdio.h>

#ifndef M_PI
#define M_PI  3.14159265358979323846
#endif

#define AREA_BY_YEAR    50

int main() {
    /* number of input rows */
    int iR;
    /* coordinates */
    float fX, fY;
    /* iterators */
    int i;

    /* read number of rows */
    scanf("%d", &iR);

    /* iterating the rows */
    for(i = 0; i < iR; i++) {
        scanf("%f %f", &fX, &fY);

        /* calculate radius^2 */
        printf("Property %d: This property will begin eroding in year %d.\n", i+1, (int)((fX*fX+fY*fY)*M_PI/2/AREA_BY_YEAR)+1);
    }

    /* end message */
    printf("END OF OUTPUT.\n");

	return 0;
}