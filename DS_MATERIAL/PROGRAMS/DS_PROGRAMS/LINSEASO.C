/* Write a program to perform linear (sequential) search in sorted list. */
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

	if(num >= arr[0] && num <= arr[n-1])
	{
		for(i = 0; i <= n-1; i++)
		{
			if(arr[i] >= num)
			{
				if(arr[i] == num)
				{
					printf("\n Number Found");
				}
				else
				{
					printf("\n Number NOT Found");
				}
				break;
			}		
		}
	}

	getch();
}