#include <stdio.h>

int main() {
 
    int vitesse = 180;
    int altitude = 3000;
    int alt_inter = 35;
    int qnh = 1015;

    float distance = 8.3;

    printf("     SPEED    |   G/S   |   LOC   |   CAT1   |  AP1        \n");
    printf("              |         |         |          | 1 FD 2      \n");
    printf("              |         |         |          | A/THR       \n");
    printf(" ________                                       _________  __ \n");
    printf("|      |               ------                  |       |  |3-|\n");
    printf("| %3d- |                ----                   |      -|  |2-|\n", vitesse + 40);
    printf("|      |        10----------------10        ° >|%03d    |  |1-|\n", alt_inter);
    printf("| %3d- |                ----                   |      -|  |  |\n", vitesse + 20);
    printf("|      |               ------               °  |=======|  |  |\n");
    printf("| %3d- < +---------------[]--------------+  ^  |%4d  ft| -===|\n", vitesse, altitude);
    printf("|      |               ------               v  |=======|  |  |\n");
    printf("| %3d- |                ----                °  |      -|  |  |\n", vitesse - 20);
    printf("|      |        10----------------10           |       |  |1-|\n");
    printf("| %3d- |                ----                ° >|%03d   -|  |2-|\n", vitesse - 40, alt_inter-10);
    printf("|______|_                 ^                    |_______|_ |3-|\n");
    printf("           °    °    °    v    °    °    °                |__|\n", vitesse);
    printf("ILS05R                                       QNH %d     \n", qnh);
    printf("108.10     ________________________________               \n");
    printf("%4.1fNM    |360 - 01 - 03 - 05 - 07 - 09 -  |              \n", distance);
    printf("          |________________________________|              \n");

    return 0;
}
