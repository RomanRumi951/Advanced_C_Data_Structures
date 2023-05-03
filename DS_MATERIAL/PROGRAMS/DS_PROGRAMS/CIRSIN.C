/* Write a C program to implement circular singly linked list using DMA. OR */
/* Write a C program that performs different operations on the circular singly linked list using DMA. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct circular_singly
{
	int value;
	struct circular_singly *next;
};

struct circular_singly *start = NULL, *node = NULL;

void append();
void insbegin();
void insend();
void insbefore();
void insafter();
void delvalue();
void display();

void main()
{
	int choice = 0;

	while(choice != 7)
	{
		clrscr();
		printf("\n MAIN MENU (Operations on Circular Singly Linked List)");
		printf("\n 1. APPEND or INSERT END");
		printf("\n 2. INSERT BEGINNING");
		printf("\n 3. INSERT BEFORE");
		printf("\n 4. INSERT AFTER");
		printf("\n 5. DELETE");
		printf("\n 6. DISPLAY");
		printf("\n 7. EXIT");
		printf("\nEnter your choice (from 1 to 7): ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				append();
				break;
			case 2:
				insbegin();
				break;
			case 3:
				insbefore();
				break;
			case 4:
				insafter();
				break;
			case 5:
				delvalue();
				break;
			case 6:
				display();
				break;
			case 7:
				break;
			default:
				printf("\n Invalid choice");
		}
		printf("\n Press any key to continue...");
		getch();
	}
}

void append()
{
	struct circular_singly *newnode = NULL;
	int num = 0;
	printf("\n Enter a number to append: ");
	scanf("%d", &num);
	newnode = (struct circular_singly *) malloc(sizeof(struct circular_singly));
	newnode -> value = num;
	if(start == NULL)
	{
		newnode -> next = newnode;
		start = newnode;
	}
	else
	{
		newnode -> next = start;
		node = start;
		while(node -> next != start)
		{
			node = node -> next;
		}
		node -> next = newnode;
	}
}

void insbegin()
{
	struct circular_singly *newnode = NULL;
	int num = 0;
	printf("\n Enter a number to insert at the beginning of the list: ");
	scanf("%d", &num);
	newnode = (struct circular_singly *) malloc(sizeof(struct circular_singly));
	newnode -> value = num;
	newnode -> next = start;
	node = start;
	while(node -> next != start)
	{
		node = node -> next;
	}
	node -> next = newnode;
	start = newnode;
}

void insbefore()
{
	struct circular_singly *newnode = NULL;
	int loc = 0, num = 0, i = 0;
	printf("\n Enter a location (position): ");
	scanf("%d", &loc);
	printf("\n Enter a number to insert before location %d in the list: ", loc);
	scanf("%d", &num);
	node = start;
	for(i = 1; i < loc-1; i++)
	{
		node = node->next;
	}
	newnode = (struct circular_singly *) malloc(sizeof(struct circular_singly));
	newnode -> value = num;
	if(loc == 1)
	{
		newnode -> next = start;
		while(node -> next != start)
		{
			node = node -> next;
		}
		node -> next = newnode;
		start = newnode;
	}
	else
	{
		newnode -> next = node -> next;
		node -> next = newnode;
	}
}

void insafter()
{
	struct circular_singly *newnode = NULL;
	int loc = 0, num = 0, i = 0;
	printf("\n Enter a location (position): ");
	scanf("%d", &loc);
	printf("\n Enter a number to insert after location %d in the listt: ", loc);
	scanf("%d", &num);
	node = start;
	for(i = 1; i < loc; i++)
	{
		node = node->next;
	}
	newnode = (struct circular_singly *) malloc(sizeof(struct circular_singly));
	newnode -> value = num;
	newnode -> next = node -> next;
	node -> next = newnode;
}

void delvalue()
{
	struct circular_singly *delnode = NULL;
	int num = 0;
	printf("\n Enter a number to delete from the list: ");
	scanf("%d", &num);	
	if(start -> value == num)
	{
		delnode = start;
		node = start;
		while(node -> next != start)
		{
			node = node -> next;
		}
		node -> next = start -> next;
		start = start -> next;
		free(delnode);
	}
	else
	{
		node = start;
		while(node -> next != start)
		{
			if(node -> next -> value == num)
			{
				delnode = node -> next;
				node -> next = node -> next -> next;
				free(delnode);
				return;
			}
			node = node -> next;
		}
		printf("\n Value %d not found in the list.", num);
	}
}

void display()
{
	printf("\n Values in the list: ");
	node = start;
	while(node -> next != start)
	{
		printf("\n %d", node -> value);
		node = node -> next;
	}
	printf("\n %d", node -> value);
}