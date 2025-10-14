#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

// 1. Static version
// 2. Dynamic version
// 3. File version

// Static version
// void InitContact(Contact* pc)
// {
// 	assert(pc);
// 	pc->count = 0;
// 	memset(pc->data, 0, sizeof(pc->data));
// }

// Expand capacity if needed
void CheckCapacity(Contact* pc)
{
	if (pc->count == pc->capacity)
	{
		PeoInfo* ptr = (PeoInfo*)realloc(pc->data, (pc->capacity + INC_SZ) * sizeof(PeoInfo));
		if (ptr == NULL)
		{
			printf("AddContact::%s\n", strerror(errno));
			return;
		}
		else
		{
			pc->data = ptr;
			pc->capacity += INC_SZ;
			printf("Capacity expanded successfully\n");
		}
	}
}

// File version
void LoadContact(Contact* pc)
{
	FILE* pfRead = fopen("contact.txt", "rb");
	if (pfRead == NULL)
	{
		perror("LoadContact");
		return;
	}
	PeoInfo tmp = { 0 };
	while (fread(&tmp, sizeof(PeoInfo), 1, pfRead) == 1)
	{
		CheckCapacity(pc);
		pc->data[pc->count] = tmp;
		pc->count++;
	}

	fclose(pfRead);
	pfRead = NULL;
}

// Dynamic version + File version
int InitContact(Contact* pc)
{
	assert(pc);
	pc->count = 0;
	pc->data = (PeoInfo*)calloc(DEFAULT_SZ, sizeof(PeoInfo));
	if (pc->data == NULL)
	{
		printf("InitContact::%s\n", strerror(errno));
		return 1;
	}
	pc->capacity = DEFAULT_SZ;
	// Load data from file into the contact list
	LoadContact(pc);
	return 0;
}

void DestroyContact(Contact* pc)
{
	assert(pc);
	free(pc->data);
	pc->data = NULL;
}

// Static version
// void AddContact(Contact* pc)
// {
// 	assert(pc);
// 	if (pc->count == 100)
// 	{
// 		printf("The contact list is full, unable to add new contact\n");
// 		return;
// 	}
//
// 	printf("Please enter name:>");
// 	scanf("%s", pc->data[pc->count].name);
// 	printf("Please enter age:>");
// 	scanf("%d", &(pc->data[pc->count].age));
// 	printf("Please enter gender:>");
// 	scanf("%s", pc->data[pc->count].sex);
// 	printf("Please enter phone number:>");
// 	scanf("%s", pc->data[pc->count].tele);
// 	printf("Please enter address:>");
// 	scanf("%s", pc->data[pc->count].addr);
//
// 	pc->count++;
// 	printf("Added successfully\n");
// }

// Dynamic version
void AddContact(Contact* pc)
{
	assert(pc);
	// Expand capacity if needed
	CheckCapacity(pc);

	printf("Please enter name:>");
	scanf("%s", pc->data[pc->count].name);
	printf("Please enter age:>");
	scanf("%d", &(pc->data[pc->count].age));
	printf("Please enter gender:>");
	scanf("%s", pc->data[pc->count].sex);
	printf("Please enter phone number:>");
	scanf("%s", pc->data[pc->count].tele);
	printf("Please enter address:>");
	scanf("%s", pc->data[pc->count].addr);

	pc->count++;
	printf("Added successfully\n");
}

void ShowContact(const Contact* pc)
{
	assert(pc);
	int i = 0;
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "Name", "Age", "Sex", "Phone", "Address");
	for (i = 0; i < pc->count; i++)
	{
		printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[i].name,
			pc->data[i].age,
			pc->data[i].sex,
			pc->data[i].tele,
			pc->data[i].addr);
	}
}

static int FindByName(Contact* pc, char name[]) // only used within this .c file
{
	assert(pc);
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		if (0 == strcmp(pc->data[i].name, name))
		{
			return i;
		}
	}
	return -1;
}

void DelContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	if (pc->count == 0)
	{
		printf("The contact list is empty, no data to delete\n");
		return;
	}
	printf("Please enter the name to delete:>");
	scanf("%s", name);

	// 1. Search
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("The person to delete does not exist\n");
		return;
	}
	int i = 0;
	for (i = pos; i < pc->count - 1; i++)
	{
		pc->data[i] = pc->data[i + 1];
	}
	pc->count--;
	printf("Deleted successfully\n");
}

void SearchContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("Please enter the name to search:>");
	scanf("%s", name);

	// 1. Search
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("The person to search does not exist\n");
		return;
	}
	// 2. Print
	printf("%-20s\t%-5s\t%-5s\t%-12s\t%-30s\n", "Name", "Age", "Sex", "Phone", "Address");
	printf("%-20s\t%-3d\t%-5s\t%-12s\t%-30s\n", pc->data[pos].name,
		pc->data[pos].age,
		pc->data[pos].sex,
		pc->data[pos].tele,
		pc->data[pos].addr);
}

void ModifyContact(Contact* pc)
{
	assert(pc);
	char name[MAX_NAME] = { 0 };
	printf("Please enter the name to modify:>");
	scanf("%s", name);

	// 1. Search
	int pos = FindByName(pc, name);
	if (pos == -1)
	{
		printf("The person to modify does not exist\n");
		return;
	}
	printf("The person has been found, starting modification\n");
	// 2. Modify
	printf("Please enter name:>");
	scanf("%s", pc->data[pos].name);
	printf("Please enter age:>");
	scanf("%d", &(pc->data[pos].age));
	printf("Please enter gender:>");
	scanf("%s", pc->data[pos].sex);
	printf("Please enter phone number:>");
	scanf("%s", pc->data[pos].tele);
	printf("Please enter address:>");
	scanf("%s", pc->data[pos].addr);

	printf("Modified successfully\n");
}

int cmp_peo_by_name(const void* e1, const void* e2)
{
	return strcmp(((PeoInfo*)e1)->name, ((PeoInfo*)e2)->name);
}

// Sort by name
void SortContact(Contact* pc)
{
	assert(pc);
	qsort(pc->data, pc->count, sizeof(PeoInfo), cmp_peo_by_name);
	printf("Sorted successfully\n");
}

// File version
void SaveContact(const Contact* pc)
{
	assert(pc);
	FILE* pfWrite = fopen("contact.txt", "wb");
	if (pfWrite == NULL)
	{
		perror("SaveContact");
		return;
	}
	// Write to file in binary format
	int i = 0;
	for (i = 0; i < pc->count; i++)
	{
		fwrite(pc->data + i, sizeof(PeoInfo), 1, pfWrite);
	}

	fclose(pfWrite);
	pfWrite = NULL;
}