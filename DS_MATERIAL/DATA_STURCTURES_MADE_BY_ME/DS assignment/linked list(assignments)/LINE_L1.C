#include <stdio.h>
//rumiroman@wordpress
//Arab!@#Rumi!@#
#include <conio.h>
#include <stdlib.h>

struct linked_list
{
	int data;
	struct linked_list *next;
} *startnode = NULL, *node = NULL;

int count();

int main()
{
	struct linked_list *newnode = NULL, *endnode = NULL, *delenode = NULL, *prevnode = NULL;
	int choice = 0, value = 0, i = 0, loc = 0;
	do
	{
		// clrscr();
		system("CLS");
		printf("\n1. Append :-");
		printf("\n2. Display :-");
		printf("\n3. Insert Beginning :-");
		printf("\n4. Delete :-");
		printf("\n5. Insert Before :-");
		printf("\n6. Insert After :-");
		printf("\n7. Exit :-");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("\nEnter a value to Append:\n");
			scanf("%d", &value);
			newnode = (struct linked_list *)malloc(sizeof(struct linked_list));
			newnode->data = value;
			newnode->next = NULL;
			if (startnode == NULL)
			{
				startnode = newnode;
			}
			else
			{
				endnode->next = newnode;
			}
			endnode = newnode;
			break;

		case 2:
			if (startnode == NULL)
			{
				printf("\n\nList is Empty:::");
			}
			else
			{
				for (node = startnode; node != NULL; node = node->next)
				{
					printf("\n%d", node->data);
				}
			}
			break;

		case 3:
			printf("\nEnter a value to insert at the beginning::");
			scanf("%d", &value);
			newnode = (struct linked_list *)malloc(sizeof(struct linked_list));
			newnode->data = value;
			newnode->next = startnode;
			startnode = newnode;

			break;

		case 4:
			if (startnode == NULL)
			{
				printf("\n\nList is Empty:::");
			}
			else
			{
				printf("\nEnter a value to delete::");
				scanf("%d", &value);
				for (node = startnode; node != NULL; node = node->next)
				{
					if (node->data == value)
					{
						delenode = node;
						if (node == startnode)
						{
							startnode = startnode->next;
						}
						else if (node == endnode)
						{
							endnode = prevnode;
							endnode->next = NULL;
						}
						else
						{
							prevnode->next = node->next;
						}
						free(delenode);
						break;
					}
					prevnode = node;
				}
			}
			break;
		case 5:
			printf("\n\nEnter a location::");
			scanf("%d", &loc);
			if (loc <= count())
			{
				printf("\n\nEnter a value to Insert Before::");
				scanf("%d", &value);
				newnode = (struct linked_list *)malloc(sizeof(struct linked_list));
				newnode->data = value;
				node = startnode;
				for (i = 1; i < loc; i++)
				{
					prevnode = node;
					node = node->next;
				}
				if (node == startnode)
				{
					newnode->next = startnode;
					startnode = newnode;
				}
				else
				{
					prevnode->next = newnode;
					newnode->next = node;
				}
			}
			else
			{
				printf("\n\nLocation Out of range::");
			}
			break;
		case 6:
			printf("\n\nEnter a location::");
			scanf("%d", &loc);
			if (loc <= count())
			{
				printf("\n\nEnter a value to Insert After::");
				scanf("%d", &value);
				newnode = (struct linked_list *)malloc(sizeof(struct linked_list));
				newnode->data = value;
				node = startnode;
				for (i = 1; i <= loc; i++)
				{
					prevnode = node;
					node = node->next;
				}
				if (node == startnode)
				{
					newnode->next = startnode;
					startnode = newnode;
				}
				else
				{
					prevnode->next = newnode;
					newnode->next = node;
				}
			}
			else
			{
				printf("\n\nLocation Out of range::");
			}

			break;

		case 7:
			exit(0);
			break;

		default:
			printf("\n\nInvalid Choice::");
		}

		printf("\n\nPress any key to continue:::");

		getch();

	} while (choice != 7);
}

int count()
{
	int c = 0;
	for (node = startnode; node != NULL; node = node->next)
	{
		c++;
	}
	return c;
}
