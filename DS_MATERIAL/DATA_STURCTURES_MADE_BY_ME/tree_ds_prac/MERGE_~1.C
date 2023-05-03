#include <stdio.h>
#include <conio.h>

struct linked_list
{
    int data;
    struct linked_list *next;
};

void create();
void merge();
void display();

void main()
{
    int choice;
    //system("CLS");
    clrscr();
    printf("1. CREATE::\n");
    printf("2. MERGE::\n");
    printf("3. DISPLAY::\n");
    printf("4. EXIT::\n");
    printf("Enter Your Choice::\n");
    scanf("%d", &choice);
    switch (choice)
    {
	case 1:
	    create();
	    break;
	case 2:
	    merge();
	    break;
	case 3:
	    display();
	    break;
	case 4:
	    exit(0);
	    break;
	default:
	    printf("INVALID CHOICE::\n");
	    break;
    }

    getch();


    //return 0;
}

void create()
{
    struct linked_list *startnode=NULL, *startnode1=NULL, *startnode2=NULL, *endnode=NULL, *newnode=NULL;
    int num;
    char ans = 'y';
    while (ans == 'y')
    {
	printf("\nEnter any Number::\n");
	scanf("%d", &num);
	newnode = (struct linked_list *)malloc(sizeof(struct linked_list));
	newnode -> data = num;
	newnode -> next = NULL;
	if (startnode == NULL)
	{
	    newnode = startnode;
	}
	else
	{
	    endnode -> next = newnode;
	}

	endnode = newnode;

	if(startnode1 == NULL)
	{
	    startnode1 = startnode;
	}
	else
	{
	    startnode2 = startnode;
	}

	printf("\nDO YOU WANT TO CONTINUE??");
	// fflush(stdin);
	// scanf("%c",&ans);
	ans = getche();
    }

    // struct linked_list *startnode=NULL, *node=NULL;
    // for(node = startnode;node != NULL;node = node->next)
    // {
    //     printf("\n%d", node->data);

    // }

       return;
}

void merge()
{

}

void display()
{
    struct linked_list *startnode=NULL, *node=NULL;
    for(node = startnode;node != NULL;node = node->next)
    {
	printf("\n%d", node->data);

    }
}