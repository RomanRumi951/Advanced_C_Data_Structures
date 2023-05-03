/* Write a C program to implement (perform) insertion sorting. */

#include <stdio.h>
#include <conio.h>

void main()
{
	int arr[25] = {0}, n = 0, i, j, k, temp = 0;
	clrscr();

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	printf("\nInput %d values: ", n);
	for(i = 0; i <= n-1; i++)
	{
		printf("\nInput the value for element %d: ", i+1);
		scanf("%d", &arr[i]);
	}

	for(i = 1; i <= n-1; i++)
	{
		temp = arr[i];
		for(j = i-1; j >= 0; j--)
		{
			if(arr[j] > temp)
			{
				arr[j+1] = arr[j];
			}
			else
			{
				break;
			}
		}
		arr[j+1] = temp;
	}

	printf("Sorted list is as follows: ");
	for(i = 0; i <= n-1; i++)
	{
		printf("\n%d", arr[i]);
	}

	getch();
}