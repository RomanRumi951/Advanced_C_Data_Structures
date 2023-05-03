/* Write a program to sort n numbers entered by the user using Quick Sorting. */

#include <stdio.h>
#include <conio.h>

void quicksort(int arr[], int lower, int upper);

void main()
{
	int arr[10] = {0}, n = 0, i = 0;
	clrscr();
	printf("\n Enter n: ");
	scanf("%d", &n);
	printf("\n Enter %d numbers: ", n);
	for(i = 0; i <= n-1; i++)
	{
		scanf("%d", &arr[i]);
	}
	quicksort(arr, 0, n-1);
	printf("\n List after sorting: ");
	for(i = 0; i <= n-1; i++)
	{
		printf("\n %d", arr[i]);
	}
	getch();
}

void quicksort(int arr[], int lower, int upper)
{
	int left = 0, right = 0, mid = 0, pivot = 0, temp = 0;
	left = lower;
	right = upper;
	mid = (lower + upper) / 2;
	pivot = arr[mid];
	while(left < right)
	{
		while(arr[left] < pivot)
		{
			left = left + 1;
		}

		while(arr[right] > pivot)
		{
			right = right - 1;
		}

		if(left < right)
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}

		if(left <= right)
		{
			left++;
			right--;
		}
	}

	if(lower < right)
	{
		quicksort(arr, lower, right);
	}

	if(left < upper)
	{
		quicksort(arr, left, upper);
	}
}