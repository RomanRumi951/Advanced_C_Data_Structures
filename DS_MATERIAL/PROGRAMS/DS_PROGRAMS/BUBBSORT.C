/* Write a C program to implement (perform) bubble sorting. */

#include <stdio.h>
#include <conio.h>

int main()
{
	int arr[25] = {0}, n = 0, i, j, temp = 0;

	//clrscr();

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
		for(j = 0; j <= (n-2)-i; j++)
		{
			if(arr[j] > arr[j+1])
			{
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
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
