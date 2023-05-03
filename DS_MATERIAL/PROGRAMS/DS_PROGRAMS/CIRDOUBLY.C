/* Write a C program to implement circular doubly linked list using DMA. OR */
/* Write a C program that performs different operations on the circular doubly linked list using DMA. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct circular_doubly
{
	int data;
	struct circular_doubly *prev, *next;
};

struct circular_doubly *start = NULL, *node = NULL;

void append();
void insbegin();
void insend();
void insbefore();
void insafter();
void delitem();
void delloc();
void sort();
void search();
void display();
void count();

void main()
{
	int choice = 0;

	do
	{
		clrscr();
		printf("\nMain Menu (Operations on the Doubly Linked List)");
		printf("\n1. Add an item at the end of the list (Creating a list)");
		printf("\n2. Insert (add) an item at the beginning of the list");
		printf("\n3. Insert (add) an item at the end of the list");
		printf("\n4. Insert (add) an item before the specified location in the list");
		printf("\n5. Insert (add) an item after the specified location in the list");
		printf("\n6. Delete an item from the list (based on number)");
		printf("\n7. Delete an item from the list (based on location)");
		printf("\n8. Sort data (information) of all nodes in the list");
		printf("\n9. Search an item (element) in the list");
		printf("\n10. Display (print) items or elements in the list");
		printf("\n11. Count the number of items in the list");
		printf("\n12. Exit");
		printf("\nEnter your choice (from 1 to 12): ");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1:
				append();			
				break;
			case 2:
				insbegin();
				break;
			case 3:
				insend();
				break;
			case 4:
				insbefore();
				break;
			case 5:
				insafter();
				break;
			case 6:
				delitem();
				break;
			case 7:
				delloc();
				break;
			case 8:
				sort();
				break;
			case 9:
				search();
				break;
			case 10:
				display();
				break;
			case 11:
				count();
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

//Create a list and append (add) a new node (item) at the end of the linked list.
void append()	//create or create_list
{
	int num = 0;
	printf("\nEnter a new item (element) to be appended (added) to the list: ");
	scanf("%d", &num);
	if(start == NULL)
	{	
		start = (struct circular_doubly *) malloc(sizeof(struct circular_doubly));
		start->prev = start;
		start->data = num;
		start->next = start;
	}
	else
	{
		node = start;
		while(node->next != start)
		{		
			node = node->next;
		}	
		node->next = (struct circular_doubly *) malloc(sizeof(struct circular_doubly));
		node->next->prev = node;
		node->next->data = num;	
		node->next->next = start;
		start->prev = node->next;
	}
}

//Create a list or insert (add) a new node (item) at the beginning of the linked list. OR
//Create a list or insert (add) the first node (item) to the list.
void insbegin()	//insfirst or addbegin or addfirst or addatbegin
{
	struct doubly_linklist *newnode = NULL;
	int num = 0;
	printf("\nEnter a new item (element) to be insterted (added) into the list: ");
	scanf("%d", &num);
	if(start == NULL)
	{
		newnode = (struct doubly_linklist *) malloc(sizeof(struct doubly_linklist));
		newnode->prev = start;
		newnode->data = num;
		newnode->next = start;
		start = newnode;
	}
	else
	{
		newnode = (struct doubly_linklist *) malloc(sizeof(struct doubly_linklist));

		node = start;
		while(node->next != start)
		{		
			node = node->next;
		}
		newnode->prev = node->next;
		newnode->data = num;
		newnode->next = start;
		node->next = newnode;
		start->prev = newnode;
		start = newnode;
	}	
}

//Insert (add) a new node (item) at the end of the linked list. OR
//Insert (add) the last node (item) to the list.
void insend()	//inslast or addend or addlast or addatend
{
	struct doubly_linklist *newnode = NULL;
	int num = 0;
	if(start == NULL)
	{
		insbegin();
		return;
	}
	printf("\nEnter a new item (element) to be insterted (added) into the list: ");
	scanf("%d", &num);
	node = start;
	while(node->next != start)
	{
		node = node->next;
	}
	newnode = (struct doubly_linklist *) malloc(sizeof(struct doubly_linklist));
	newnode->prev = node;
	newnode->data = num;
	newnode->next = start;
	node->next = newnode;
	start->prev = newnode;
}

//Insert (add) a new node (item) before (at) the specified location in the linked list.
void insbefore()	//addbefore or add_at_spec_loc or insmiddle or addmiddle
{
	struct doubly_linklist *newnode = NULL;
	int num = 0, loc = 0, i = 0;
	if(start == NULL)
	{
		printf("\nList is empty (underflow).");
		return;
	}
	printf("\nEnter position (location): ");
	scanf("%d", &loc);
	printf("\nEnter a new item (element) to be insterted (added) into the list: ");
	scanf("%d", &num);
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
	newnode = (struct doubly_linklist *) malloc(sizeof(struct doubly_linklist));
	newnode->prev = node->prev;	
	newnode->data = num;
	newnode->next = node;
	if(node->prev == NULL)
	{
		start = newnode;
	}
	else
	{
		node->prev->next = newnode;
	}
	node->prev = newnode;
}

//Insert (add) a new node (item) after the specified location in the linked list.
void insafter()	//addafter or insmiddle or addmiddle
{
	struct doubly_linklist *newnode = NULL;
	int num = 0, loc = 0, i = 0;
	if(start == NULL)
	{
		printf("\nList is empty (underflow).");
		return;
	}
	printf("\nEnter position (location): ");
	scanf("%d", &loc);
	printf("\nEnter a new item (element) to be insterted (added) into the list: ");
	scanf("%d", &num);
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
	newnode = (struct doubly_linklist *) malloc(sizeof(struct doubly_linklist));
	newnode->prev = node;
	newnode->data = num;
	newnode->next = node->next;
	if(node->next != NULL)
	{
		node->next->prev = newnode;
	}
	node->next = newnode;	
}

//Delete (remove) an existing node (item) from the linked list (based on number).
//Delete (remove) the specified item (value) from the linked list (Method 1).
void delitem()	//delnode or delfirst or dellast or delmiddle or delspeval or remove
{
	struct doubly_linklist *delnode = NULL;
	int num = 0;
	if(start == NULL)
	{
		printf("\nList is empty (underflow).");
		return;
	}
	printf("\nEnter an item to be deleted (removed) from the list: ");
	scanf("%d", &num);	
	if(start->data == num)
	{
		delnode = start;
		if(start->next != NULL)
		{
			start->next->prev = NULL;
		}
		start = start->next;
		free(delnode);
	}
	else
	{
		node = start;
		while(node->next != NULL)
		{
			if(node->next->data == num)
			{
				delnode = node->next;
				if(node->next->next != NULL)
				{
					node->next->next->prev = node;
				}
				node->next = node->next->next;
				free(delnode);
				return;
			}
			node = node->next;
		}
		printf("\nElement %d not found in the list.", num);
	}
}

/*//Delete (remove) an existing node (item) from the linked list (based on number).
//Delete (remove) the specified item (value) from the linked list (Method 2).
void delitem()	//delnode or delfirst or dellast or delmiddle or delspeval or remove
{
	struct doubly_linklist *nxtnode = NULL;
	int num = 0;
	if(start == NULL)
	{
		printf("\nList is empty (underflow).");
		return;
	}
	printf("\nEnter an item to be deleted (removed) from the list: ");
	scanf("%d", &num);	
	if(start->data == num)
	{
		nxtnode = start->next;
		if(start->next != NULL)
		{
			start->next->prev = NULL;
		}
		free(start);
		start = nxtnode;
	}
	else
	{
		node = start;
		while(node->next != NULL)
		{
			if(node->next->data == num)
			{
				nxtnode = node->next->next;
				if(node->next->next != NULL)
				{
					node->next->next->prev = node;
				}
				free(node->next);
				node->next = nxtnode;
				return;
			}
			node = node->next;
		}
		printf("\nElement %d not found in the list.", num);
	}
}*/

//Delete (remove) an existing node (item) from the linked list (based on location).
//Delete (remove) the item (value) at the specified location (position) from the linked list.
void delloc()	//delfirst or dellast or delmiddle or delspeloc or remove
{
	struct doubly_linklist *delnode = NULL;
	int loc = 0, i = 0;
	if(start == NULL)
	{
		printf("\nList is empty (underflow).");
		return;
	}
	printf("\nEnter the location of the item to be deleted from the list: ");
	scanf("%d", &loc);
	if(loc == 1)
	{
		delnode = start;
		if(start->next != NULL)
		{
			start->next->prev = NULL;
		}
		start = start->next;
		free(delnode);
	}
	else
	{
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
		if(node->next->next != NULL)
		{
			node->next->next->prev = node;
		}
		node->next = node->next->next;
		free(delnode);
	}
}

//Sort data (information) of all nodes in the list.
void sort()
{
	struct doubly_linklist *currnode = NULL;
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

//Search the specified node (item) in the unsorted (or sorted) linked list.
void search()	//If list is unsorted.
{
	int num = 0, loc = 1;
	if(start == NULL)
	{
		printf("\nList is empty (underflow).");
		return;
	}
	printf("\nEnter an item to be searched in the list: ");
	scanf("%d", &num);
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
		/*//if list is sorted
		if(node->data > num)
		{
			break;
		}*/
	}
	printf("\nSearch is unsuccessful.");
	printf("\n%d is not in the list.", num);
}

//Display (print) elements or items in the linked list.
//Displays the data (information) of all nodes in the list.
//Displays the contents of the linked list.
void display()	//print
{
	if(start == NULL)
	{
		printf("\nList is empty (underflow).");
		return;
	}
	printf("\nCurrent contents of the linked list: ");
	node = start;
	printf("\n%p %p", start, node);
	while(node != NULL)
	{
		printf("\n%p %d %p %p", node, node->data, node->prev, node->next);
		node = node->next;
	}
	printf("\n%p %p\n", start, node);
}

//Count the number of nodes present in the linked list.
void count()
{
	int c = 0;
	if(start == NULL)
	{
		printf("\nList is empty (underflow).");
		return;
	}
	node = start;
	while(node != NULL)
	{
		c = c + 1;
		node = node->next;
	}
	printf("\nNumber of items (elements) in the linked list is %d.", c);
}