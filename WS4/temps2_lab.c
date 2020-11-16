//==============================================
// Name:           Dale
// Student Number: #########
// Email:          @myseneca.ca
// Section:        NVV
// Workshop:       4 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Put your code below:

#include <stdio.h>
#define SIZE 11

int main(void) {

    int i = 0;
    int iLow, iHigh, iDays;
    int highTemp[SIZE] = { 0 };
    int lowTemp[SIZE] = { 0 };
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

    return 0;
}
