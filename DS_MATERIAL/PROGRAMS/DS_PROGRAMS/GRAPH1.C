/* Write a program to implement insert and depth first search traversal
operation on a graph using DMA. */
/* Write a program to create a graph and perform depth first search traversal
operation on the graph using DMA. */
/* Write a program for creating and traversing (dfs) a graph using DMA. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct graph
{
	int value;
	struct graph *next;
};

struct graph *start[8] = {NULL};

int i = 0, stack[8] = {0}, visited[8] = {0}, top = -1, x = 0;

void insert();
void display();
void dfs();
void push(int data);
int pop();

void main()
{
	int choice = 0;
	while(choice != 4)
	{
		clrscr();
		printf("\n Operations on Graph (Main Menu)");
		printf("\n 1. INSERT");
		printf("\n 2. DISPLAY");
		printf("\n 3. DEPTH FIRST SEARCH");
		printf("\n 4. EXIT");
		printf("\n Enter your choice (from 1 to 4): ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				display();
				break;
			case 3:
				dfs();
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
	struct graph *newnode = NULL, *node = NULL;
	int adja_nodes = 0, num = 0, j = 0;
	printf("\n Enter the number of adjacent nodes: ");
	scanf("%d", &adja_nodes);
	for(j = 1; j <= adja_nodes; j++)
	{
		printf("\n Enter value %d to insert: ", j);
		scanf("%d", &num);
		newnode = (struct graph *) malloc(sizeof(struct graph));
		newnode -> value = num;
		newnode -> next = NULL;
		if(start[i] == NULL)
		{
			start[i] = newnode;
		}
		else
		{
			node = start[i];
			while(node -> next != NULL)
			{
				node = node -> next;
			}
			node -> next = newnode;
		}
	}
	i = i + 1;
}

void display()
{
	struct graph *node = NULL;
	int j = 0;
	for(j = 0; j <= i-1; j++)
	{
		printf("\n Adjacency List %d of Graph:", j+1);
		node = start[j];
		while(node -> next != NULL)
		{
			printf(" %d", node -> value);
			node = node -> next;
		}
		printf(" %d", node -> value);
	}
}

void dfs()
{
	struct graph *node = NULL;
	int j = 0, k = 0, flag = 0, data = 0;
	push(start[0]->value);
	while(top != -1)
	{
		data = pop();
		for(j = 0; j <= i-1; j++)
		{
			if(start[j]->value == data)
			{
				node = start[j];
				break;
			}
		}
		while(node->next != NULL)
		{
			flag = 0;
			for(k = 0; k <= x-1; k++)
			{
				if(visited[k] == node->next->value)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				push(node->next->value);
			}
			node = node->next;
		}
	}
}

void push(int data)
{
	if(top != 7)
	{
		top = top + 1;
		stack[top] = data;
		visited[x++] = data;
	}
}

int pop()
{
	int data = 0;
	if(top != -1)
	{
		data = stack[top];
		top = top - 1;
		printf(" %d ", data);
	}
	return data;
}