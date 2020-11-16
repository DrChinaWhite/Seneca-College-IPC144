//==============================================
// Name:           Dale
// Student Number: #########
// Email:          @myseneca.ca
// Section:        NVV
// Workshop:       4 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Place your code below

#include <stdio.h>
#define SIZE 11

int main(void) {

    int i = 0;
    int iLow, iHigh, iDays, iLoDay, iHiDay, iPeriod;
    int iHighest = -100;
    int iLowest = 100;
    int highTemp[SIZE] = { 0 };
    int lowTemp[SIZE] = { 0 };
    double dTotal = 0, dAvg;
    char title[] = "---=== IPC Temperature Calculator V2.0 ===---";
    char header[] = "Day  Hi  Low";

    // display title
    printf("%s\n", title);

    // prompt user for number of days to track tempterature
    printf("Please enter the number of days, between 3 and 10, inclusive: ");
    scanf("%d", &iDays);
    printf("\n");

    // display an error if the user gives an invalid entry
    while ((iDays < 3) || (iDays > 10)) {

        printf("Invalid entry, please enter a number between 3 and 10, inclusive: ");
        scanf("%d", &iDays);
        printf("\n");
    }

    // prompt the user for high and low values of each day and store the data in parrallel arrays
    for (i = 0; i < iDays; i++) {

        printf("Day %d - High: ", i + 1);
        scanf("%d", &iHigh);

        printf("Day %d - Low: ", i + 1);
        scanf("%d", &iLow);

        highTemp[i] = iHigh;
        lowTemp[i] = iLow;
    }

    // display table header
    printf("\n");
    printf("%s\n", header);

    // print the data from arrays as a table
    for (i = 0; i < iDays; i++) {
    
        printf("%d    %d    %d\n", i + 1, highTemp[i], lowTemp[i]);   
    }
    
    printf("\n");

    // replace variable with highest and lowest temperature
    for (i = 0; i < iDays; i++) {

        if (highTemp[i] > iHighest) {

            iHighest = highTemp[i];
            iHiDay = i + 1;
        }

        if (lowTemp[i] < iLowest) {

            iLowest = lowTemp[i];
            iLoDay = i + 1;
        }
    }

    printf("The highest temperature was %d, on day %d\n", iHighest, iHiDay);
    printf("The lowest temperature was %d, on day %d\n", iLowest, iLoDay);
    printf("\n");

    do {

        printf("Enter a number between 1 and %d to see the average temperature for the entered "
               "number of days, enter a negative number to exit: ", iDays);
        scanf("%d", &iPeriod);
        printf("\n");

        while ((iPeriod > iDays) || (iPeriod == 0)) {

            printf("Invalid entry, please enter a number between 1 and %d, inclusive: ", iDays);
            scanf("%d", &iPeriod);
            printf("\n");
        }

        if (iPeriod > 0) {

            for (i = 0; i < iPeriod; i++) {

                dTotal = dTotal + highTemp[i] + lowTemp[i];
            }

            dAvg = (dTotal / ((double)iPeriod * 2));
            printf("The average temperature up to day %d is: %.2f", iPeriod, dAvg);
            printf("\n\n");
            dTotal = 0;
        }

    } while (iPeriod >= 0);

    printf("Goodbye!\n");

    return 0;
}
