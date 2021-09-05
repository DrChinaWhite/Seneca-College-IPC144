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
// |        contents below...                        |
// +-------------------------------------------------+

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contactHelpers.h"
#define MAXCONTACTS 5

//--------------------------------
// Function Definitions
//--------------------------------

// Clear the standard input buffer
void clearKeyboard(void)
{
	while (getchar() != '\n'); // empty execution code block on purpose
}

// pause function definition goes here:
void pause(void)
{
	printf("(Press Enter to Continue)");
	clearKeyboard();
}

// getInt: Empty function definition goes here:
int getInt(void)
{
	int value;
	char NL = 'x';

	scanf(" %d%c", &value, &NL);

	while (NL != '\n') {

		clearKeyboard();
		printf("*** INVALID INTEGER *** <Please enter an integer>: ");
		scanf(" %d%c", &value, &NL);
	}

	return value;
}

// getIntInRange: Empty function definition goes here:
int getIntInRange(int min, int max)
{
	int iValue = getInt();

	while ((iValue < min) || (iValue > max)) {

		printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ", min, max);
		iValue = getInt();
	}

	return iValue;
}

// yes: Empty function definition goes here:
int yes(void)
{
	char yn;
	char nl;
	scanf("%c%c", &yn, &nl);

	if (nl != '\n') {

		clearKeyboard();

	}

	while ((yn != 'Y' && yn != 'y' && yn != 'N' && yn != 'n') || (nl != '\n')) {

		printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
		scanf("%c%c", &yn, &nl);
		
		if (nl != '\n') {

			clearKeyboard();

		}
	}
	if (yn == 'Y' || yn == 'y') {

		return 1;

	} else {

		return 0;

	}
}


// menu: Empty function definition goes here:
int menu(void)
{
	printf("Contact Management System\n");
	printf("-------------------------\n");
	printf("1. Display contacts\n");
	printf("2. Add a contact\n");
	printf("3. Update a contact\n");
	printf("4. Delete a contact\n");
	printf("5. Search contacts by cell phone number\n");
	printf("6. Sort contacts by cell phone number\n");
	printf("0. Exit\n\n");
	printf("Select an option:> ");

	return getIntInRange(0, 6);
	printf("\n");
}

// contactManagerSystem: Empty function definition goes here:
void contactManagerSystem(void)
{
	int option = 0;
	int yn;

	struct Contact testing[MAXCONTACTS] =
	{ { { "Rick", {'\0'}, "Grimes" },
		{ 11, "Trailer Park", 0, "A7A 2J2", "King City" },
		{ "4161112222", "4162223333", "4163334444" } },
		{
			{ "Maggie", "R.", "Greene" },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9051112222", "9052223333", "9053334444" } },
		{
			{ "Morgan", "A.", "Jones" },
			{ 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
			{ "7051112222", "7052223333", "7053334444" } },
		{
			{ "Sasha", {'\0'}, "Williams", },
			{ 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
			{ "9052223333", "9052223333", "9054445555" } },
	};

	do {
		option = menu();
		switch (option)
		{
		case 0:
			printf("\nExit the program? (Y)es/(N)o: ");
			yn = yes();
			if (yn == 1) {
				printf("\nContact Management System: terminated\n");
				return;
			}
			else {
				printf("\n");
			}
			break;

		case 1:
			displayContacts(testing, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 2:
			addContact(testing, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 3:
			updateContact(testing, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 4:
			deleteContact(testing, MAXCONTACTS); 
			printf("\n");
			pause();
			printf("\n");
			break;

		case 5:
			searchContacts(testing, MAXCONTACTS);
			pause();
			printf("\n");
			break;

		case 6:
			sortContacts(testing, MAXCONTACTS);
			pause();
			printf("\n");
			break;
		}
	} while ((option >= 0) || (option <= 6));

	return;
}

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------

void getTenDigitPhone(char phoneNum[])
{
	int digits = 1;
	int i;
	while (digits) {

		scanf("%10s", phoneNum);
		clearKeyboard();

		if (strlen(phoneNum) == 10) {

			digits = 0;

			for (i = 0; i < 10; i++) {

				if (!isdigit(phoneNum[i])) {

					digits = 1;
					i = 10;

				}
			}
		}
		if (digits) {

			printf("Enter a 10-digit phone number: ");

		}
	}
}

// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]) 
{	
	int i;
	for (i = 0; i < size; i++)
	{
		if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {

			return i;

		}
	}
	return -1;
}

// displayContactHeader:
void displayContactHeader(void) 
{	
	printf("\n");
	printf("+-----------------------------------------------------------------------------+\n");
	printf("|                              Contacts Listing                               |\n");
	printf("+-----------------------------------------------------------------------------+\n");
}

// displayContactFooter:
void displayContactFooter(int count) 
{	
	printf("+-----------------------------------------------------------------------------+\n");
	printf("Total contacts: %d\n\n", count);
}

// displayContact:
void displayContact(const struct Contact* contact)
{
	if ((*contact).name.middleInitial[0] == '\0') {

		printf(" %s %s\n", (*contact).name.firstName, (*contact).name.lastName);

	} else {

		printf(" %s %s %s\n", (*contact).name.firstName,
		(*contact).name.middleInitial, (*contact).name.lastName);

	}
	
	printf("    C: %-10s   H: %-10s   B: %-10s\n", (*contact).numbers.cell,
	(*contact).numbers.home, (*contact).numbers.business);

	if ((*contact).address.apartmentNumber > 0) {

		printf("       %d %s, Apt# %d, %s, %s\n",
		(*contact).address.streetNumber, (*contact).address.street,
		(*contact).address.apartmentNumber, (*contact).address.city,
		(*contact).address.postalCode);

	} else {

		printf("       %d %s, %s, %s\n", (*contact).address.streetNumber,
		(*contact).address.street, (*contact).address.city,
		(*contact).address.postalCode);

	}
}
// displayContacts:
void displayContacts(const struct Contact contacts[], int size) 
{	
	int i;
	int count = 0;

	displayContactHeader();

	for (i = 0; i < size; i++)
	{
		if (strlen(contacts[i].numbers.cell) != 0)
		{
			displayContact(&contacts[i]);
			count++;
		}
	}

	displayContactFooter(count);
}

// searchContacts:
void searchContacts(const struct Contact contacts[], int size) 
{	
	char phoneNum[11];
	int index;

	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNum);

	index = findContactIndex(contacts, size, phoneNum);
	if (index == -1) {

		printf("*** Contact	NOT FOUND ***\n\n");

	} else {

		printf("\n");
		displayContact(&contacts[index]);
		printf("\n");

	}
}

// addContact:
void addContact(struct Contact contacts[], int size) 
{
	int i;
	for (i = 0; i < size; i++) {
		
		if (strlen(contacts[i].numbers.cell) == 0) {
			break;
		}
	}
	
	if (i == size) {

		printf("\n*** ERROR: The contact list is full! ***\n\n");

	} else {

		printf("\n");
		getContact(&contacts[i]);
		printf("--- New contact added! ---\n\n");

	}
}

// updateContact:
void updateContact(struct Contact contacts[], int size) {
	
	char phoneNum[11];
	int index;
	int yn;
	
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNum);
	
	index = findContactIndex(contacts, size, phoneNum);
	if (index == -1) {

		printf("*** Contact NOT FOUND ***\n\n");

	} else {

		printf("\nContact found:\n");
		displayContact(&contacts[index]);
		printf("\n");

		printf("Do you want to update the name? (y or n): ");
			yn = yes();
			if (yn == 1) {

				getName(&contacts[index].name);

			}

		printf("Do you want to update the address? (y or n): ");
			yn = yes();
			if (yn == 1) {

				getAddress(&contacts[index].address);

			}

		printf("Do you want to update the numbers? (y or n): ");
			yn = yes();
			if (yn == 1) {

				getNumbers(&contacts[index].numbers);

			}

		printf("--- Contact Updated! ---\n\n");
	}
}

// deleteContact:
void deleteContact(struct Contact contacts[], int size) 
{
	char phoneNum[11];
	int index;
	int yn;
	
	printf("\nEnter the cell number for the contact: ");
	getTenDigitPhone(phoneNum);
	
	index = findContactIndex(contacts, sizeof(contacts), phoneNum);
	if (index == -1) {

		printf("*** Contact NOT FOUND ***\n\n");

	} else {

		printf("\nContact found:\n");
		displayContact(&contacts[index]);
		printf("\n");
		
		printf("CONFIRM: Delete this contact? (y or n): ");
		yn = yes();
		if (yn == 1) {

			contacts[index].numbers.business[0] = '\0';
			contacts[index].numbers.cell[0] = '\0';
			contacts[index].numbers.home[0] = '\0';
			printf("--- Contact deleted! ---\n");

		}
	}
}

// sortContacts:
void sortContacts(struct Contact contact[], int size) 
{
	int i;
	int j;
	struct Contact temp;
	for (i = 0; i < size - 1; i++)
	{
		for (j = i + 1; j < size; j++)
		{
			if (strlen(contact[i].numbers.cell) != 0 && strlen(contact[j].numbers.cell) != 0) {
				if (strcmp(contact[i].numbers.cell, contact[j].numbers.cell) > 0) {
					temp = contact[i];
					contact[i] = contact[j];
					contact[j] = temp;
				}
			}
		}
	}
	printf("\n--- Contacts sorted! ---\n\n");
}