/* Write a program to implement insert and breadth first search traversal
operation on a graph using DMA. */
/* Write a program to create a graph and perform breadth first search traversal
operation on the graph using DMA. */
/* Write a program for creating and traversing (bfs) a graph using DMA. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAXSIZE 10

struct graph
{
	int value;
	struct graph *next;
};

struct graph *start[MAXSIZE] = {NULL};

int i = 0, queue[MAXSIZE] = {0}, visited[MAXSIZE] = {0}, front = -1, rear = -1, x = 0;

void insert();
void display();
void bfs();
void add(int element);
int delet();

void main()
{
	int choice = 0;
	while(choice != 3)
	{
		clrscr();
		printf("\n Operations on Graph (Main Menu)");
		printf("\n 1. INSERT");
		printf("\n 2. BREADTH FIRST SEARCH TRAVERSAL");
		printf("\n 3. EXIT");
		printf("\n Enter your choice (from 1 to 3): ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				insert();
				break;
			case 2:
				bfs();
				break;
			case 3:
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

void bfs()
{
	struct graph *node = NULL;
	int j = 0, k = 0, flag = 0, element = 0;
	add(start[0] -> value);
	while(front != -1)
	{
		element = delet();
		for(j = 0; j <= i - 1; j++)
		{
			if(start[j] -> value == element)
			{
				node = start[j];
				break;
			}
		}
		while(node -> next != NULL)
		{
			flag = 0;
			for(k = 0; k <= x - 1; k++)
			{
				if(visited[k] == node -> next -> value)
				{
					flag = 1;
					break;
				}
			}
			if(flag == 0)
			{
				add(node -> next -> value);
			}
			node = node -> next;
		}
	}
}

void add(int element)
{
	if(rear != MAXSIZE - 1)
	{
		rear = rear + 1;
		queue[rear] = element;
		if(front == -1)
		{
			front = 0;
		}
		visited[x++] = element;
	}
}

int delet()
{
	int element = 0;
	if(front != -1)
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
		printf(" %d ", element);
	}
	return element;
}