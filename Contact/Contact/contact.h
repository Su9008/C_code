#pragma once
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<stdlib.h>

#define DEFAULT_SZ 3 // initial capacity
#define INC_SZ 2     // capacity increment
#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 10
#define MAX_TELE 12
#define MAX_ADDR 30

// Type declaration
typedef struct PeoInfo
{
	char name[MAX_NAME];
	int age;
	char sex[MAX_SEX];
	char tele[MAX_TELE];
	char addr[MAX_ADDR];
} PeoInfo;

// Address book
// Static version
// typedef struct Contact
// {
// 	PeoInfo data[MAX]; // each person's information
// 	int count;         // number of people
// } Contact;

// Dynamic version
typedef struct Contact
{
	PeoInfo* data;  // each person's information
	int count;      // number of people
	// current capacity of the address book
	int capacity;
} Contact;

// Initialize the contact list
int InitContact(Contact* pc);

// Dynamic version
// Destroy the contact list
void DestroyContact(Contact* pc);

// Add a new contact
void AddContact(Contact* pc);

// Print all contacts
void ShowContact(const Contact* pc);

// Delete a specific contact
void DelContact(Contact* pc);

// Search for a specific contact
void SearchContact(Contact* pc);

// Modify a specific contact
void ModifyContact(Contact* pc);

// Sort the contacts in the address book
// Sort by name
// Sort by age
// ...
void SortContact(Contact* pc);

// File version
// Save the contact list to a file
void SaveContact(const Contact* pc);

// Load contact information from a file into the contact list
void LoadContact(const Contact* pc);