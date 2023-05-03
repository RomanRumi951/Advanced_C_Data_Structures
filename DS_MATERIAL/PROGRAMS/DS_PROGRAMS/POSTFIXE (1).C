/* Write a program to evaluate postfix expression using stack. */

#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>

void push(int value);
int pop();

int stack[15], top = -1;

void main()
{
	char expr[15];
	int length = 0, i = 0, num1 = 0, num2 = 0, num3 = 0;
	clrscr();
	printf("\n Enter a postfix expression to evaluate: ");
	scanf("%s", expr);
	length = strlen(expr);
	for(i = 0; i <= length - 1; i++)
	{
		printf("\n %d %d", expr[i], '0');
		if(isdigit(expr[i]))
		{
			push(expr[i] - '0');
		}
		else
		{
			num1 = pop();
			num2 = pop();
			switch(expr[i])
			{
				case '+':
					num3 = num2 + num1;
					break;
				case '-':
					num3 = num2 - num1;
					break;
				case '*':
					num3 = num2 * num1;
					break;
				case '/':
					num3 = num2 / num1;
					break;
			}
			push(num3);
		}
	}
	printf("\n Result of postfix expression = %d", pop());
	getch();
}

void push(int value)
{
	if(top == 14)
	{
		printf("\n Stack is Full (Stack Overflow)");
	}
	else
	{
		top = top + 1;
		stack[top] = value;
	}
}

int pop()
{
	int value = 0;
	if(top == -1)
	{
		printf("\n Stack is Empty (Stack Underflow)");
	}
	else
	{
		value = stack[top];
		top = top - 1;
	}
	return value;
}