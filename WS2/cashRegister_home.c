//==============================================
// Name:           Dale
// Student Number: #########
// Email:          @myseneca.ca
// Section:        NVV
// Workshop:       2 (at-home)
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// Paste your in-lab code below and upgrade it to the at-home specifications
#include <stdio.h>
#include <math.h>

	int main(void)
	{
		double dAmountOwed, dGST;
		int iChange, iAmountOwed;
		const double dTax = 0.13;

		printf("Please enter the amount to be paid: $");
		scanf("%lf", &dAmountOwed);

		//Calculate GST required and display new balance
		dGST = dAmountOwed * dTax + 0.005;
		printf ("GST: %.2lf\n", dGST);

		//Calculate amount with GST
		dAmountOwed = dAmountOwed + dGST;
		printf("Balance owing: $%.2lf\n", dAmountOwed);

		//Calculate amount of loonies required
		iChange = (int)dAmountOwed;
		dAmountOwed = dAmountOwed - iChange;
		printf("Loonies required: %d, balance owing $%.2lf\n", iChange, dAmountOwed);

		//Cast double to float and return an interger
		iAmountOwed = (float)(dAmountOwed * 100.0);

		//Calculate amount of quarters required
		iChange = (iAmountOwed / 25);
		iAmountOwed = iAmountOwed % 25;
		printf("Quarters required: %d, balance owing $%.2lf\n", iChange, (double)iAmountOwed / 100);

		//Calculate amount of dimes required
		iChange = (iAmountOwed / 10);
		iAmountOwed = iAmountOwed % 10;
		printf("Dimes required: %d, balance owing $%.2lf\n", iChange, (double)iAmountOwed / 100);

		//Calculate amount of nickels required
		iChange = (iAmountOwed / 5);
		iAmountOwed = iAmountOwed % 5;
		printf("Nickels required: %d, balance owing $%.2lf\n", iChange, (double)iAmountOwed / 100);

		//Calculate amount of pennies required
		iChange = (iAmountOwed / 1);
		iAmountOwed = iAmountOwed % 1;
		printf("Pennies required: %d, balance owing $%.2lf\n", iChange, (double)iAmountOwed / 100);

		return 0;
	}
