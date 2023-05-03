/* Write a C program to implement a stack using an array. OR
   Write a C program that performs basic opertaions on a stack using an array. */

#include <stdio.h>
#include <conio.h>

#define MAXSIZE 5

void push();
void pop();
void display();

int stack[MAXSIZE], top = -1;
void main()
{
	int choice = 0;
	while (choice != 4)
	{
		clrscr();
		printf("\nMain Menu (Basic Operations On Stack):");
		printf("\n1. PUSH");
		printf("\n2. POP");		
		printf("\n3. DISPLAY");
		printf("\n4. EXIT");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				push();
				break;
			case 2:
				pop();
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

void push()
{
	int item = 0;
	if(top == MAXSIZE-1)
	{
		printf("\nStack is full (stack overflow)");
	}
	else
	{
		printf("\nEnter the element (item) to be pushed into the top of the stack: ");
		scanf("%d", &item);
		top = top + 1;
		stack[top] = item;	
	}
}

void pop()
{
	int item = 0;
	if(top == -1)
	{
		printf("\nStack is empty (stack underflow).");
	}
	else
	{
		item = stack[top];
		top = top - 1;
		printf("\nThe item (element) popped from the top of the stack is %d", item);
	}
}

void display()
{
	int i = 0;
	if(top == -1)
	{
		printf("\nStack is empty (stack underflow).");
	}
	else
	{
		printf("\nItems (elements) in the stack are:");
		for(i = top; i >= 0; i--)
		{
			printf("\n%d", stack[i]);
		}
	}
}