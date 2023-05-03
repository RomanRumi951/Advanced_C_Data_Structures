/* Write a program to perform insert, delete, and display operations on priority queue. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct prio_queue
{
	int value, priority;
	struct prio_queue *next;
};

struct prio_queue *front = NULL, *rear = NULL, *node = NULL;

void insert();
void delet();
void display();

void main()
{
	int choice = 0;
	while(choice != 4)
	{
		clrscr();
		printf("\n Main Menu (Operations on Priority Queue)");
		printf("\n 1. INSERT");
		printf("\n 2. DELETE");
		printf("\n 3. DISPLAY");
		printf("\n 4. EXIT");
		printf("\n Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				delet();
				break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("\n Invalid Choice");
		}
		printf("\n Press any key to continue...");
		getch();
	}
}

void insert()
{
	struct prio_queue *newnode = NULL;
	int num = 0, prio = 0;
	printf("\n Enter a number to insert: ");
	scanf("%d", &num);
	printf("\n Enter a priority of the number: ");
	scanf("%d", &prio);
	newnode = (struct prio_queue *) malloc(sizeof(struct prio_queue));
	newnode -> value = num;
	newnode -> priority = prio;
	if(front == NULL)
	{
		newnode -> next = NULL;
		front = newnode;
		rear = newnode;
	}
	else if(front -> priority > prio)
	{
		newnode -> next = front;
		front = newnode;
	}
	else
	{
		node = front;
		while(node -> next != NULL)
		{
			if(node -> next -> priority > prio)
			{
				newnode -> next = node -> next;
				node -> next = newnode;
				return;
			}
			node = node -> next;
		}
		newnode -> next = NULL;
		node -> next = newnode;
		rear = newnode;
	}
}

void delet()
{
	struct prio_queue *delnode = NULL;
	if(front == NULL)
	{
		printf("\n Queue is Empty (Queue Underflow)");
	}
	else
	{
		delnode = front;
		printf("\n Value deleted: %d", front -> value);
		front = front -> next;
		if(front == NULL)
		{
			rear = NULL;
		}
		free(delnode);
	}
}

void display()
{
	if(front == NULL)
	{
		printf("\n Queue is Empty (Queue Underflow)");
	}
	else
	{
		node = front;
		printf("\n Values in the queue are: ");
		while(node -> next != NULL)
		{
			printf("\n %d", node -> value);
			node = node -> next;
		}
		printf("\n %d", node -> value);
	}
}