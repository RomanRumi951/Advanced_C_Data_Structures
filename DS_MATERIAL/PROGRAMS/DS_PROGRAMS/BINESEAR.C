/* Write a C program to implement (perform) binary search. */

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int main()
{
	int arr[25] = {0}, i, n = 0, num = 0, lower, upper, mid, flag = 0;
	system("CLS");	
	printf("\n Enter the number of elements: ");
	scanf("%d", &n);

	printf("\n Input %d values: ", n);
	for(i = 0; i <= n-1; i++)
	{
		printf("\n Input the value for element %d: ", i+1);
		scanf("%d", &arr[i]);
	}
	
	printf("\n Enter a number to search: ");
	scanf("%d", &num);

	lower = 0;
	upper = n-1;
	while(lower <= upper)
	{
		mid = (lower + upper) / 2;
		if(arr[mid] == num)
		{
			flag = 1;
			break;
		}
		else if(arr[mid] > num)
		{
			upper = mid -1;
		}
		else
		{
			lower = mid + 1;
		}
	}

	if(flag == 1)
	{
		printf("\n Number is in the list.");
	}
	else
	{
		printf("\n Number is not in the list.");
	}

	getch();
	return 0;
}