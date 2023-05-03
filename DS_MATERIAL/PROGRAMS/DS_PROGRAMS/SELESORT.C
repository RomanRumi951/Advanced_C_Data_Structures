/* Write a C program to implement (perform) selection sorting. */
#include <stdio.h>
#include <conio.h>

void main()
{
	int arr[25] = {0}, n = 0, i, j, temp = 0;

	clrscr();

	printf("Enter the number of elements: ");
	scanf("%d", &n);

	printf("\nInput %d values: ", n);
	for(i = 0; i <= n-1; i++)
	{
		printf("\nInput the value for element %d: ", i+1);
		scanf("%d", &arr[i]);
	}

	for(i = 0; i <= n-2; i++)
	{
		for(j = i+1; j <= n-1; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("Sorted list is as follows: ");
	for(i = 0; i <= n-1; i++)
	{
		printf("\n%d", arr[i]);
	}

	getch();
}