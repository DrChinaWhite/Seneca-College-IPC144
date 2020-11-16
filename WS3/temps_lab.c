//==============================================
// Name:           Dale
// Student Number: #########
// Email:          @myseneca.ca
// Section:        NVV
// Workshop:       3 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>
#define NUMS 3

int main(void) {

    int iLow, iHigh;
    int i = 0;
    const int HIGH = 41;
    const int LOW = -41;
    char title[] = "---=== IPC Temperature Analyzer ===---";
    char incorrect[] = "Incorrect values, temperatures must be in the range -40 to 40, "
                       "high must be greater than low.";

    // display title
    printf("%s\n", title);

    for (i = 1; i <= NUMS; i++) {

        printf("Enter the high value for day %d: ", i);
        scanf("%d", &iHigh);
        printf("\n");

        printf("Enter the low value for day %d: ", i);
        scanf("%d", &iLow);
        printf("\n");

        while ((iLow > iHigh) || (iLow <= LOW) || (iHigh >= HIGH)) {

            printf("%s\n", incorrect);
            printf("\n");

            printf("Enter the high value for day %d: ", i);
            scanf("%d", &iHigh);
            printf("\n");

            printf("Enter the low value for day %d: ", i);
            scanf("%d", &iLow);
            printf("\n");
        }
    }
    
    return 0;
}
