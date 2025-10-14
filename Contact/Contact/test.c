#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"

enum Option
{
	EXIT,
	ADD,
	DEL,
	SEARCH,
	MODIFY,
	SHOW,
	SORT
};

void menu()
{
	printf("*********************************\n");
	printf("***** 1.add       2.del     *****\n");
	printf("***** 3.search    4.modify  *****\n");
	printf("***** 5.show      6.sort    *****\n");
	printf("***** 0.exit                *****\n");
	printf("*********************************\n");
}

int main()
{
	int input = 0;
	Contact con; // address book
	// Initialize the address book
	InitContact(&con);
	do
	{
		menu();
		printf("Please choose:>");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			SortContact(&con);
			break;
		case EXIT:
			SaveContact(&con); // file version: save before exit
			DestroyContact(&con);
			printf("Exiting address book\n");
			break;
		default:
			printf("Invalid selection\n");
			break;
		}
	} while (input);
	return 0;
}
