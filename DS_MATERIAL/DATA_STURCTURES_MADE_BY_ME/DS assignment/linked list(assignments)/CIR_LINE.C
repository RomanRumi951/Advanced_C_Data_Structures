#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct linked_list
{
    int data;
    struct linked_list *next;
}*startnode=NULL, *node=NULL;

int count();

void main()
{
    struct linked_list *newnode=NULL,  *endnode=NULL, *delenode=NULL, *prevnode=NULL;
    int choice=0, value=0, i=0, loc=0;
    do
    {
	clrscr();
	printf("\n1. Append :-");
	printf("\n2. Display :-");
	printf("\n3. Insert Beginning :-");
	printf("\n4. Delete :-");
	printf("\n5. Insert Before :-");
	printf("\n6. Insert After :-");
	printf("\n7. Exit :-");
	printf("\n\nEnter your choice::");
	scanf("%d", &choice);
	switch(choice)
	{
	    case 1:
		printf("\nEnter a value to Append:\n");
		scanf("%d", &value);
		newnode = (struct linked_list *)malloc(sizeof(struct linked_list));
		newnode->data = value;
		if(startnode == NULL)
		{
		    newnode->next = newnode;
		    startnode = newnode;
		}
		else
		{
		    newnode->next = startnode;
		    endnode->next = newnode;
		}
		endnode = newnode;
		break;

	    case 2:
		if(startnode == NULL)
		{
			printf("\n\nList is Empty:::");
		}
		else
		{
			node = startnode;
			do
			{
			    printf("\n%d", node->data);
			    node = node->next;

			}while(node != startnode);
		}
		break;

	    case 3:
		printf("\nEnter a value to insert at the beginning::");
		scanf("%d", &value);
		newnode = (struct linked_list *)malloc(sizeof(struct linked_list));
		newnode->data = value;
		newnode->next = startnode;
		startnode = newnode;
		endnode->next = startnode;

		break;

	    case 4:
		if(startnode == NULL)
		{
			printf("\n\nList is Empty:::");
		}
		else
		{
			printf("\nEnter a value to delete::");
			scanf("%d", &value);
			node=startnode;
			do
			{
				if(node->data==value)
				{
					delenode=node;
					if(node==startnode)
					{
						startnode=startnode->next;
						endnode->next = startnode;
						if(node == endnode)
						{
							startnode = NULL;
							endnode = NULL;
						}
					}
					else if(node==endnode)
					{
						endnode = prevnode;
						endnode->next = startnode;
					}
					else
					{
						prevnode->next = node->next;
					}
					free(delenode);
					break;
				}
				prevnode=node;
				node=node->next;
			}while(node!=startnode);
		}
		break;
	    case 5:
		printf("\n\nEnter a location::");
		scanf("%d", &loc);
		if(loc <= count())
		{
			printf("\n\nEnter a value to Insert Before::");
			scanf("%d", &value);
			newnode = (struct linked_list *) malloc(sizeof(struct linked_list));
			newnode -> data = value;
			node = startnode;
			for(i=1;i<loc;i++)
			{
				prevnode = node;
				node = node->next;
			}
			if(node==startnode)
			{
				newnode->next = startnode;
				startnode = newnode;
				endnode->next=startnode;
			}
			else
			{
				prevnode -> next = newnode;
				newnode -> next = node;
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
		if(loc <= count())
		{
			printf("\n\nEnter a value to Insert After::");
			scanf("%d", &value);
			newnode = (struct linked_list *) malloc(sizeof(struct linked_list));
			newnode -> data = value;
			node = startnode;
			for(i=1;i<=loc;i++)
			{
				prevnode = node;
				node = node->next;
			}
			if(node==startnode)
			{
				newnode->next = startnode;
				startnode = newnode;
			}
			else
			{
				prevnode -> next = newnode;
				newnode -> next = node;
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


    }while(choice != 7);
}

int count()
{
	int c = 0;
	node = startnode;
	do
	{
	      c++;
	      node = node->next;

	}while(node != startnode);
	return c;
}