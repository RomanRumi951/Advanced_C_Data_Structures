#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct linked_list
{
	struct linked_list *prev;
	int data;
	struct linked_list *next;
}*startnode=NULL,*node=NULL;
int count();
void main()
{
	struct linked_list  *endnode=NULL,  *newnode=NULL, *delenode=NULL;
	int value, choice, loc=0, i=0;
	do
	{
		clrscr();
		printf("\n\n1. Append:");
		printf("\n\n2. Display:");
		printf("\n\n3. Insert Beginning:");
		printf("\n\n4. DELETE:");
		printf("\n\n5. INSERT Before:");
		printf("\n\n6. Insert After:");
		printf("\n\n7. EXIT:");
		printf("\n\nEnter a choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("\n\nEnter a value to Append::");
				scanf("%d",&value);
				newnode = (struct linked_list *) malloc(sizeof(struct linked_list));
				newnode -> data = value;
				newnode -> next = startnode;
				if(startnode == NULL)
				{
					newnode -> prev = newnode;
					newnode -> next = newnode;
					startnode = newnode;
				}
				else
				{
					newnode -> prev = endnode;
					endnode -> next = newnode;
					newnode -> next = startnode;
					startnode -> prev = newnode;
				}
				endnode = newnode;
				break;
			case 2:
				if(startnode == NULL)
				{
					printf("\n\nList is Empty::");
				}
				else
				{
					node=startnode;
					do
					{
						printf("\n%d",node->data);
						node=node->next;
					}while(node!=startnode);
					printf("\n\nIn Reverse::");
					node=endnode;
					do
					{
						printf("\n%d",node->data);
						node=node->prev;
					}while(node!=endnode);
				}
				break;
			case 3:
				printf("\n\nEnter a value to insert at the beginning::");
				scanf("%d", &value);
				newnode = (struct linked_list *) malloc(sizeof(struct linked_list));
				newnode -> data = value;
				newnode -> prev = endnode;
				newnode -> next = startnode;
				startnode -> prev = newnode;
				endnode -> next = newnode;
				startnode = newnode;
				break;
			case 4:
				if(startnode == NULL)
				{
					printf("\n\nList is Empty::");
				}
				else
				{
					printf("\n\nEnter a value to be deleted::");
					scanf("%d",&value);
					node=startnode;
					do
					{
						if(node->data==value)
						{
							delenode = node;
							if(node==startnode)
							{
								startnode->next->prev = endnode;
								startnode = startnode -> next;
								endnode -> next = startnode;
								if(node == endnode)
								{
									startnode = NULL;
									endnode = NULL;
								}
							}
							else if(node == endnode)
							{
								endnode->prev->next = startnode;
								endnode = endnode -> prev;
								startnode -> prev = endnode;
							}
							else
							{
								node->prev->next = node->next;
								node->next->prev = node->prev;
							}
							free(delenode);
							break;
						}
						node=node->next;
					}while(node!=startnode);
				}
				break;
			case 5:
				printf("\n\nEnter a location::");
				scanf("%d",&loc);
				if(loc <= count())
				{
					printf("\n\nEnter a value::");
					scanf("%d",&value);
					newnode = (struct linked_list *) malloc(sizeof(struct linked_list));
					newnode -> data = value;
					node = startnode;
					for(i=1;i<loc;i++)
					{
						node = node->next;
					}
					if(node == startnode)
					{
						newnode -> prev = endnode;
						newnode -> next = startnode;
						startnode -> prev = newnode;
						endnode -> next = newnode;
						startnode = newnode;
					}
					else
					{
						node->prev->next = newnode;
						newnode->prev= node->prev;
						newnode->next= node;
						node->prev = newnode;
					}
				}
				else
				{
					printf("\n\nLocation out of range::");
				}
				break;
			case 6:
				printf("\n\nEnter a location::");
				scanf("%d",&loc);
				if(loc <= count())
				{
					printf("\n\nEnter a value::");
					scanf("%d",&value);
					newnode = (struct linked_list *) malloc(sizeof(struct linked_list));
					newnode -> data = value;
					node = startnode;
					for(i=1;i<=loc;i++)
					{
						node = node->next;
					}
					if(node == startnode)
					{
						newnode -> prev = endnode;
						newnode -> next = startnode;
						startnode -> prev = newnode;
						endnode -> next = newnode;
						startnode = newnode;
					}
					else
					{
						node->prev->next = newnode;
						newnode->prev= node->prev;
						newnode->next= node;
						node->prev = newnode;
					}
				}
				else
				{
					printf("\n\nLocation out of range::");
				}
				break;
			case 7:exit(0);
				break;
			default:
				printf("\n\nInvalid Choice::");
				break;

		}
		printf("\n\nPress anykey to continue::");
		getch();

	}while(choice!=7);
}
int count()
{
	int c = 0;
	node=startnode;
	do
	{
		c++;
		node=node->next;
	}while(node!=startnode);
	return c;

}
