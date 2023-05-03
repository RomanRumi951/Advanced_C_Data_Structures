#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void main()
{
int a[5], front = -1, rear = -1, value = 0, choice = 0, i = 0;
do
{
clrscr();
printf("\n Different operation::");
printf("\n 1. ADD");
printf("\n 2. DELETE");
printf("\n 3. DISPLAY");
printf("\n 4. EXIT");
printf("\n Enter your choice: ");
scanf("%d", &choice);
switch(choice)
{
case 1:
if((rear == 4)
{
printf("\n Queue is full");
}
else
{
printf("Enter a value to be added: ");
scanf("%d", &value);
rear = rear + 1;
a[rear] = value;
if(front == -1)
{
front = 0;
}
}
break;
case 2:
if(front == -1)
{
printf("Queue is empty");
}
else
{
value = a[front];
if(front == rear)
{
front = -1;
rear = -1;
}
else
{
front = front + 1;
}
printf("Deleted value is %d.", value);
}
break;
case 3:
if(front == -1)
{
printf("Queue is empty");
}
else
{
printf("Queue values: ");
for(i = front; i <= rear; i++)
{
printf("\n %d", a[i]);
}
}
break;
case 4:
exit(0);
break;
default:
printf("\n Invalid choice");
}
getch();
} while(choice != 4);
}