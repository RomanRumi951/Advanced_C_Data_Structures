/* Write a C program that implements a circular queue as (using) an array. OR
   Write a C program that performs the basic opertaions on a circular queue using an array. OR
   Write a C program for circular queue with the use of (using) an array. */

#include <stdio.h>
#include <conio.h>

#define MAXSIZE 5

void add();
void delete();
void display();

int queue[MAXSIZE], front = -1, rear = -1;
void main()
{
	int choice = 0;
	while(choice != 4)
	{
		clrscr();
		printf("\nMain Menu (Basic Operations On Queue)");
		printf("\n1. ADD (INSERT)");
		printf("\n2. DELETE (REMOVE)");
		printf("\n3. DISPLAY");
		printf("\n4. EXIT");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				add();
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
				printf("\nInvalid choice");
		}
		getch();
	}
}

void add()
{
	int element = 0;
	if((rear == MAXSIZE-1 && front == 0) || (rear+1 == front))
	{
		printf("\nQueue is full (queue overflow).");
	}
	else
	{
		printf("\nEnter the element to be added (inserted) into the queue: ");
		scanf("%d", &element);
		if(rear == MAXSIZE-1)
		{
			rear = 0;
		}
		else
		{
			rear = rear + 1;
		}
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
		printf("\nQueue is empty (queue underflow).");
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
			if(front == MAXSIZE-1)
			{
				front = 0;
			}
			else
			{
				front = front + 1;
			}
		}
		printf("\nThe element deleted from the queue is %d.", element);
	}
}

void display(int queue[])
{
	int i = 0;
	if(front == -1)
	{
		printf("\nQueue is empty (queue underflow).");
	}
	else
	{
		if(rear >= front)
		{
			printf("\nElements in the circular queue are:");
			for(i = front; i <= rear; i++)
			{
				printf("\n%d", queue[i]);
			}
		}
		else
		{
			printf("\nElements in the circular queue are:");
			for(i = front; i <= MAXSIZE-1; i++)
			{
				printf("\n%d", queue[i]);
			}
			for(i = 0; i <= rear; i++)
			{
				printf("\n%d", queue[i]);
			}
		}
	}
}