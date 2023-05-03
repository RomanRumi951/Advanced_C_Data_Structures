/* Write a C program to implement singly linked list using DMA. OR */
/* Write a C program that performs different operations on the singly linked list using DMA. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct singly_linklist
{
	int data;
	struct singly_linklist *next;
};

void append(struct singly_linklist *, int);
void insbegin(struct singly_linklist *, int);
void insafter(struct singly_linklist *, int, int);
void insloc(struct singly_linklist *, int, int);
void delnode(struct singly_linklist *, int);
void delloc(struct singly_linklist *, int);
void sort(struct singly_linklist *);
void search(struct singly_linklist *, int);
void srchsl(struct singly_linklist *, int);
void display(struct singly_linklist *);
void count(struct singly_linklist *);

struct singly_linklist *node = NULL;

void main()
{
	int choice = 0, num = 0, loc = 0;
	struct singly_linklist *start = NULL;

	do
	{
		clrscr();
		printf("\nMain Menu (Operations on the Linked List)");
		printf("\n1. APPEND (ADD OR CREATE)");
		printf("\n2. INSERT (ADD) BEGINNING (FIRST)");
		printf("\n3. INSERT (ADD) AFTER");
		printf("\n4. INSERT (ADD) AT SPECIFIED LOCATION");
		printf("\n5. DELETE (REMOVE) (based on number)");
		printf("\n6. DELETE (REMOVE) (based on location)");
		printf("\n7. SORT");
		printf("\n8. SEARCH (in Unsorted List)");
		printf("\n9. SEARCH (in Sorted List)");
		printf("\n10. DISPLAY (PRINT)");
		printf("\n11. COUNT");
		printf("\n12. EXIT");
		printf("\nEnter your choice (from 1 to 12): ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				printf("\nList before addition:");
				display(start);
				printf("\nEnter a new item to be appended (added) to the list: ");
				scanf("%d", &num);
				append(start, num);
				printf("\nList after addition:");
				display(start);
				break;
			case 2:
				printf("\nList before insertion:");
				display(start);
				printf("\nEnter a new item to be inserted (added) into the list: ");
				scanf("%d", &num);
				insbegin(start, num);
				printf("\nList after insertion:");
				display(start);
				break;
			case 3:
				printf("\nList before insertion:");
				display(start);
				printf("\nEnter position (location): ");
				scanf("%d", &loc);
				printf("\nEnter a new item to be inserted (added) into the list: ");
				scanf("%d", &num);
				insafter(start, loc, num);
				printf("\nList after insertion:");
				display(start);
				break;
			case 4:
				printf("\nList before insertion:");
				display(start);
				printf("\nEnter position (location): ");
				scanf("%d", &loc);
				printf("\nEnter a new item to be inserted (added) into the list: ");
				scanf("%d", &num);
				insloc(start, loc, num);
				printf("\nList after insertion:");
				display(start);
				break;
			case 5:
				printf("\nList before deletion:");
				display(start);
				printf("\nEnter an item to be deleted (removed) from the list: ");
				scanf("%d", &num);
				delnode(start, num);
				printf("\nList after deletion:");
				display(start);
				break;
			case 6:
				printf("\nList before deletion:");
				display(start);
				printf("\nEnter position (location): ");
				scanf("%d", &loc);
				delloc(start, loc);
				printf("\nList after deletion:");
				display(start);
				break;
			case 7:
				printf("\nList before sorting:");
				display(start);
				sort(start);
				printf("\nList after sorting:");
				display(start);
				break;
			case 8:
				printf("\nEnter an item to be searched in the list: ");
				scanf("%d", &num);
				search(start, num);
				break;
			case 9:
				printf("\nEnter an item to be searched in the list: ");
				scanf("%d", &num);
				srchsl(start, num);
				break;
			case 10:
				display(start);
				break;
			case 11:
				count(start);
				break;
			case 12:
				exit(0);
				break;
			default:
				printf("\nInvalid choice");
		}
		printf("\nPress any key to continue...");
		getch();
	} while(choice != 12);
}

//Appends (adds) a new node at the end of the linked list.
void append(struct singly_linklist *start, int num)	  //OR create
{
	if(start == NULL)
	{
		//If the list is empty, create first node.
		start = (struct singly_linklist *) malloc(sizeof(struct singly_linklist));
		start->data = num;
		start->next = NULL;
	}
	else
	{
		node = start;
		//Go to last node.
		while(node->next != NULL)
		{
			//Move from the current node to the next node.
			node = node->next;	         //Go to the next node.
		}
		//Add node at the end of the list.
		node->next = (struct singly_linklist *) malloc(sizeof(struct singly_linklist));
		node->next->data = num;
		node->next->next = NULL;
	}
}

//Inserts (adds) a new node at the beginning of the linked list.
void insbegin(struct singly_linklist *start, int num)   //OR insfirst OR addatbegin
{
	struct singly_linklist *newnode = NULL;
	//Insert (add) new node.
	newnode = (struct singly_linklist *) malloc(sizeof(struct singly_linklist));
	newnode->data = num;
	newnode->next = start;
	start = newnode;
}

//Inserts (adds) a new node after the specified location in the linked list.
void insafter(struct singly_linklist *start, int loc, int num)	  //OR addafter
{
	struct singly_linklist *newnode = NULL;
	int i = 0;
	node = start;
	for(i = 1; i < loc; i++)
	{
		node = node->next;
		if(node == NULL)
		{
			printf("\nPosition out of range (end of the list).");
			printf("\nThere are less than %d elements in the list.", loc);
			return;
		}
	}
	//Insert (add) new node.
	newnode = (struct singly_linklist *) malloc(sizeof(struct singly_linklist));
	newnode->data = num;
	newnode->next = node->next;
	node->next = newnode;
}

//Inserts (adds) a new node at the specified location in the linked list.
void insloc(struct singly_linklist *start, int loc, int num)
{
	struct singly_linklist *newnode = NULL;
	int i = 0;	
	node = start;
	for(i = 1; i < loc-1; i++)
	{
		node = node->next;
		if(node == NULL)
		{
			printf("\nPosition out of range (end of the list).");
			printf("\nThere are less than %d elements in the list.", loc);
			return;
		}
	}
	//Insert (add) new node.
	newnode = (struct singly_linklist *) malloc(sizeof(struct singly_linklist));
	newnode->data = num;
	newnode->next = node->next;
	node->next = newnode;	
}

//Deletes (removes) the first or specified node from the linked list (based on number).
void delnode(struct singly_linklist *start, int num)
{
	struct singly_linklist *delnode = NULL;
	//struct linked_list *nextnode = NULL;
	if(start->data == num)
	{
		//Deletes the first node from the beginning of the list.
		delnode = start;
		start = start->next;
		free(delnode);
		
		/*nextnode = start->next;
		free(start)	;
		start = nextnode;*/
	}
	else
	{
		//Deletes the intermediate (in between) nodes in the list.
		node = start;
		while(node->next != NULL)
		{
			if(node->next->data == num)
			{
				delnode = node->next;
				node->next = node->next->next;
				free(delnode);
				
				/*nextnode = node->next->next;
				free(node->next);
				node->next = nextnode;*/

				return;
			}
			node = node->next;
		}
		printf("\nElement %d is not found in the list.", num);
	}
}	

//Deletes (removes) the first or specified node from the linked list (based on location).
void delloc(struct singly_linklist *start, int loc)
{
	struct singly_linklist *delnode = NULL;
	//struct linked_list *nextnode = NULL;
	int i = 0;
	if(loc == 1)
	{
		//Deletes the first node from the beginning of the list.
		delnode = start;
		start = start->next;
		free(delnode);
	
		/*nextnode = start->next;
		free(start)	;
		start = nextnode;*/
	}
	else
	{
		//Deletes the intermediate (in between) nodes in the list.
		node = start;
		for(i = 1; i < loc-1; i++)
		{
			node = node->next;
			if(node == NULL)
			{
				printf("\nPosition out of range (end of the list).");
				printf("\nThere are less than %d elements in the list.", loc);
				return;
			}
		}
		delnode = node->next;
		node->next = node->next->next;
		free(delnode);
				
		/*nextnode = node->next->next;
		free(node->next);
		node->next = nextnode;*/
	}
}

//Sorts data (information) of all nodes in the list.
void sort(struct singly_linklist *start)
{
	struct singly_linklist *currnode = NULL;
	int temp = NULL;
	node = start;
	while(node != NULL)
	{
		currnode = node->next;
		while(currnode != NULL)
		{
			if(node->data > currnode->data)
			{
				temp = node->data;
				node->data = currnode->data;
				currnode->data = temp;
			}
			currnode = currnode->next;
		}
		node = node->next;
	}
}

//Search the specified node in the unsorted list.
void search(struct singly_linklist *start, int num)	//If list is unsorted.
{
	int loc = 1;
	node = start;
	while(node != NULL)
	{
		if(node->data == num)
		{
			printf("\nSearch is successful.");
			printf("\nSearch element %d found at location %d.", num, loc);
			return;
		}
		node = node->next;
		loc++;
	}
	printf("\nSearch is unsuccessful.");
	printf("\n%d is not in the list.", num);
}

//Search the specified node in the sorted list.
void srchsl(struct singly_linklist *start, int num)	//If list is sorted.
{
	int loc = 1;
	node = start;
	while(node != NULL)
	{
		if(node->data == num)
		{
			printf("\nSearch is successful.");
			printf("\nSearch element %d found at location %d.", num, loc);
			return;
		}
		node = node->next;
		loc++;
		if(node->data > num)
		{
			break;
		}
	}
	printf("\nSearch is unsuccessful.");
	printf("\n%d is not in the list.", num);
}

//Displays the data (information) of all nodes in the list.
//Displays the contents of the linked list.
//Example of traversing the linked list (traverse the entire linked list).
void display(struct singly_linklist *start)	//OR print
{
	printf("\nCurrent contents of the linked list: ");
	node = start;
	printf("\n\n%p %p\n", start, node);
	while(node != NULL)
	{
		printf("\n%p %d %p %p %p", node, node->data, &node->data, node->next, &node->next);
		node = node->next;
	}
	printf("\n\n%p %p\n", start, node);
}

//Counts the number of nodes present in the linked list.
//Example of traversing the linked list (traverse the entire linked list).
void count(struct singly_linklist *start)
{
	int c = 0;
	//Traverse the linked list till the last node is reached.
	node = start;
	while(node != NULL)
	{
		c = c + 1;
		node = node->next;     //Go to the next node.
	}
	printf("\nNumber of items (elements) in the linked list is %d.", c);
}