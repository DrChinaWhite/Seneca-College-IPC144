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

#include "contacts.h"

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-3 |
// |        contents below...                        |
// +-------------------------------------------------+

//--------------------------------
// Function Prototypes
//--------------------------------

// Clear the standard input buffer
void clearKeyboard(void);

// pause:
// Pause execution of function
void pause(void);

// getInt:
// Returns a valid interger
int getInt(void);

// getIntInRange:
// Returns a valid interger in range
int getIntInRange(int min, int max);

// yes:
// Prompts user for single character
int yes(void);

// menu:
// Prompt user for valid interger between 0-6 inclusive
int menu(void);

// contactManagerSystem:
// Shows system menu and recieves user selection
void contactManagerSystem(void);

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);

// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);

// displayContactHeader
// put function prototype here:
void displayContactHeader(void);

// displayContactFooter:
// put function prototype here:
void displayContactFooter(int count);

// displayContact:
// put function prototype here:
void displayContact(const struct Contact* contact);

// displayContacts:
// put function prototype here:
void displayContacts(const struct Contact contacts[], int size);

// searchContacts:
// put function prototype here:
void searchContacts(const struct Contact contacts[], int size);

// addContact:
// put function prototype here:
void addContact(struct Contact contacts[], int size);

// updateContact:
// put function prototype here:
void updateContact(struct Contact contacts[], int size);

// deleteContact:
// put function prototype here:
void deleteContact(struct Contact contacts[], int size);

// sortContacts:
// put function prototype here:
void sortContacts(struct Contact contacts[], int size);
