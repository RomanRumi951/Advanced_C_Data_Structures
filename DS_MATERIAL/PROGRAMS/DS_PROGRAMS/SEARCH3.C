/* Write a program to perform binary search. */
#include <stdio.h>
#include <conio.h>

void main()
{
	int arr[10] = {1,2,3,9,11,13,17,35,57,90}, lower, upper, mid, num = 0, flag = 0;
	clrscr();
	lower = 0;
	upper = 9;

	printf("Enter a number to search: ");
	scanf("%d", &num);

	while(lower <= upper)
	{
		mid = (lower+upper)/2;
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
		printf("Number is in the list.");
	}
	else
	{
		printf("Number is not in the list.");
	}

	getch();
}