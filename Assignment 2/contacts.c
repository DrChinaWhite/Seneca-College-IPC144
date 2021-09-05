//==============================================
// Name:           Dale Hawkins
// Student Number: #########
// Email:          @myseneca.ca
// Section:        NVV
// Date:           Dec 4th, 2020
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================

#define _CRT_SECURE_NO_WARNINGS

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        source code below...                     |
// +-------------------------------------------------+

#include <stdio.h>
#include "contacts.h"
#include "contactHelpers.h"
#include <string.h>
#include <ctype.h>

// getName:
void getName(struct Name* name)
{
    printf("Please enter the contact's first name: ");
    scanf("%30[^\n]", name->firstName);
    clearKeyboard();

    printf("Do you want to enter a middle initial(s)? (y or n): ");

    int yesNo = yes();
    if (yesNo == 1)
    {
        printf("Please enter the contact's middle initial(s): ");
        scanf("%6[^\n]", name->middleInitial);
        clearKeyboard();
    } else {
        name->middleInitial[0] = '\0';
    }

    printf("Please enter the contact's last name: ");
    scanf("%35[^\n]", name->lastName);
    clearKeyboard();
}

// getAddress:
void getAddress(struct Address* address)
{
    do
    {
        printf("Please enter the contact's street number: ");
        address->streetNumber = getInt();

        if (address->streetNumber < 1) {
            printf("*** INVALID STREET NUMBER *** <must be a positive number>: ");
            address->streetNumber = getInt();
        }

    } while (address->streetNumber < 1);

    printf("Please enter the contact's street name: ");
    scanf("%40[^\n]", address->street);
    clearKeyboard();

    printf("Do you want to enter an apartment number? (y or n): ");

    int yesNo = yes();
    if (yesNo == 1)
    {
        do
        {
            printf("Please enter the contact's apartment number: ");
            address->apartmentNumber = getInt();

            if (address->apartmentNumber < 1) {
                printf("*** INVALID APARTMENT NUMBER *** <must be a positive number>: ");
                address->apartmentNumber = getInt();
            }

        } while (address->apartmentNumber < 1);
    }

    printf("Please enter the contact's postal code: ");
    scanf("%7[^\n]", address->postalCode);
    clearKeyboard();

    printf("Please enter the contact's city: ");
    scanf("%40[^\n]", address->city);
    clearKeyboard();
}

// getNumbers:
void getNumbers(struct Numbers* numbers)
{
    printf("Please enter the contact's cell phone number: ");
    getTenDigitPhone(numbers->cell);

    printf("Do you want to enter a home phone number? (y or n): ");
    int yesNo = yes();
    if (yesNo == 1)
    {
        printf("Please enter the contact's home phone number: ");
        getTenDigitPhone(numbers->home);
    } else {
        *numbers->home = '\0';
    }

    printf("Do you want to enter a business phone number? (y or n): ");

    yesNo = yes();
    if (yesNo == 1)
    {
        printf("Please enter the contact's business phone number: ");
        getTenDigitPhone(numbers->business);
    }
    else {
        *numbers->business = '\0';
    }
}

// getContact:
void getContact(struct Contact* contact)
{
    getName(&contact->name);
    getAddress(&contact->address);
    getNumbers(&contact->numbers);
}
