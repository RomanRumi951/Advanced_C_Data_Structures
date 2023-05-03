/* Write a C program to implement (perform) merge sorting. */
#include <stdio.h>
#include <conio.h>

void partition(int arr[], int low, int high);
void mergesort(int arr[], int low, int mid, int high);

void main()
{
	int arr[100], n = 0, i = 0;
	clrscr();
	printf("\n Enter n: ");
	scanf("%d", &n);
	printf("\n Enter %d numbers to sort: ", n);
	for(i = 0; i <= n-1; i++)
	{
		scanf("%d", &arr[i]);
	}
	partition(arr, 0, n-1);
	printf("\n List after sorting: ");
	for(i = 0; i <= n-1; i++)
	{
		printf("\n %d", arr[i]);
	}
	getch();
}

void partition(int arr[], int low, int high)
{
	int mid = 0;
	if(low < high)
	{
		mid = (low + high) / 2;
		partition(arr, low, mid);
		partition(arr, mid+1, high);
		mergesort(arr, low, mid, high);
	}
}

void mergesort(int arr[], int low, int mid, int high)
{
	int i, j, k, temp[100];
	i = low;
	j = mid + 1;
	k = low;
	while((i <= mid) && (j <= high))
	{
		if(arr[i] <= arr[j])
		{
			temp[k] = arr[i];
			i++;
		}
		else
		{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}

	while(i <= mid)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}

	while(j <= high)
	{
		temp[k] = arr[j];
		j++;
		k++;
	}

	for(i = low; i <= high; i++)
	{
		arr[i] = temp[i];
	}
}