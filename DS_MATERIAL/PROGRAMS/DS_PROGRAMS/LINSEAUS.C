/* Write a program to perform linear (sequential) search in unsorted list. */
#include <stdio.h>
#include <conio.h>

void main()
{
	int arr[25] = {0}, n = 0, i, num = 0;
	clrscr();

	printf("\n Enter the number of elements: ");
	scanf("%d", &n);

	printf("\n Input %d values: ", n);
	for(i = 0; i <= n-1; i++)
	{
		printf("\n Input the value for element %d: ", i+1);
		scanf("%d", &arr[i]);
	}

	printf("\n Enter number to search: ");
	scanf("%d", &num);

	for(i = 0; i <= n-1; i++)
	{
		if(arr[i] == num)
		{
			printf("\n Number Found");	
			break;	
		}
	}

	if(i == n)
	{
		printf("\n Number NOT Found");
	}

	getch();
}