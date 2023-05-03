/* Write a C program to implement a queue using (as) an array. OR
   Write a C program that performs basic opertaions on a queue using 
   an array. OR
   Write a C program for queue with the use of an array. OR
   Write a menu driven C program for the queue with the use of array. */

#include <stdio.h>
#include <conio.h>

#define MAXSIZE 5

int queue[MAXSIZE], front = -1, rear = -1;
void insert();
void delete();
void display();

void main()
{
	int choice = 0;
	while(choice != 4)
	{
		clrscr();
		printf("\n Main Menu (Basic Operations on Queue)");
		printf("\n 1. INSERT");
		printf("\n 2. DELETE");
		printf("\n 3. DISPLAY");
		printf("\n 4. Exit");
		printf("\n Enter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				insert();			
				break;
			case 2:
				delete();
				break;
			case 3:
				display();
				break;
			case 4:				
				break;
			default:
				printf("\n Invalid choice");
		}
		printf("\n Press any key to continue...");
		getch();
	}
}

void insert()
{
	int element = 0;
	if(rear == MAXSIZE-1)
	{
		printf("\n Queue is full (queue overflow).");
	}
	else
	{	
		printf("\n Enter the element to be inserted (added) into the queue: ");
		scanf("%d", &element);
		rear = rear + 1;
		queue[rear] = element;
		if(front == -1)
		{
			front = 0;
		}
	}	
}

void delete()
{
	int element = 0;
	if(front == -1)
	{
		printf("\n Queue is empty (queue underflow).");
	}
	else
	{
		element = queue[front];
		if(front == rear)
		{
			front = -1;
			rear = -1;
		}
		else
		{
			front = front + 1;
		}
		printf("\n The element from the queue is %d.", element);
	}
}

void display()
{
	int i = 0;
	if(front == -1)
	{
		printf("\n Queue is empty (queue underflow).");
	}
	else
	{
		printf("\n Elements in the queue are:");
		for(i = front; i <= rear; i++)
		{
			printf("\n %d", queue[i]);
		}
	}
}