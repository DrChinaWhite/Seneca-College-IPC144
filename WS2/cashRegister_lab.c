//==============================================
// Name:           Dale
// Student Number: #########
// Email:          @myseneca.ca
// Section:        NZZ
// Workshop:       2 (in-lab)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Start your code below:
#include <stdio.h>
#include <math.h>

int main(void)
{
	double dAmountOwed;
	int iChange, iAmountOwed;

	printf("Please enter the amount to be paid: $");
	scanf("%lf", &dAmountOwed);

	//Calculate amount of loonies required
	iChange = (int)dAmountOwed;
	dAmountOwed = dAmountOwed - iChange;
	printf("Loonies required: %d, balance owing $%.2lf\n", iChange, dAmountOwed);
	
	//Cast a double into a float to convert to interger
	iAmountOwed = (float)(dAmountOwed*100.0);
	
	//Calculate amount of quarters required
	iChange = (iAmountOwed / 25);
	iAmountOwed = iAmountOwed % 25;
	printf("Quarters required: %d, balance owing $%.2lf\n", iChange, (double)iAmountOwed / 100);

	return 0;
}
