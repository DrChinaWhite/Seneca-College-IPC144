//==============================================
// Name:           Dale
// Student Number: #########
// Email:          @myseneca.ca
// Section:        NVV
// Workshop:       3 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>
#define NUMS 4

int main(void) {

    int iLow, iHigh;
    int iHiDay = 0;
    int iLoDay = 0;
    int iHighest = -40;
    int iLowest = 40;
    int iTotalHigh = 0;
    int iTotalLow = 0;
    int i = 0;
    double avgLow, avgHigh, avgTotal;
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

        if (iHighest < iHigh) {
                
            iHighest = iHigh;
            iHiDay = i;
        }

        if (iLowest > iLow) {
                
            iLowest = iLow;
            iLoDay = i;
        }

        iTotalHigh = iTotalHigh + iHigh;
        iTotalLow = iTotalLow + iLow;
    }

    avgTotal = ((double)iTotalHigh + (double)iTotalLow) / (double)(NUMS * 2);
    avgHigh = (double)iTotalHigh / NUMS;
    avgLow = (double)iTotalLow / NUMS;

    printf("The average (mean) LOW temperature was: %.2lf\n", avgLow);
    printf("The average (mean) HIGH temperature was: %.2lf\n", avgHigh);
    printf("The average (mean) temperature was: %.2lf\n", avgTotal);
    printf("The highest temperature was %d, on day %d\n", iHighest, iHiDay);
    printf("The lowest temperature was %d, on day %d\n", iLowest, iLoDay);

    return 0;
}
