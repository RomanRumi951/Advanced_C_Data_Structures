/* Write a program to implement bucket sorting. */

#include <stdio.h>
#include <conio.h>

void main()
{
	int bucket [10][10] = {0}, a[8] = {0}, i = 0, j = 0, k = 0, max = 0, temp = 0, buck[10] = {0};
	clrscr();

	printf("\n Enter 8 numbers: ");
	for(i = 0; i <= 7; i++)
	{
		scanf("%d", &a[i]);
	}

	max = a[0];
	for(i = 0; i <= 7; i++)
	{
		if(a[i] > max)
		{
			max = a[i];
		}
	}

	for(i = 0; i <= 7; i++)
	{
		j = buck[a[i]/10]++;
		bucket[a[i]/10][j] = a[i];
	}

	for(k = 0; k <= max/10; k++)
	{
		for(i = 1; i <= buck[k]-1; i++)
		{
			temp = bucket[k][i];
			for(j = i-1; j >= 0; j--)
			{
				if(bucket[k][j] > temp)
				{
					bucket[k][j+1] = bucket[k][j];
				}
				else
				{
					break;
				}
			}
			bucket[k][j+1] = temp;
		}
	}

	k = 0;
	for(i = 0; i <= max/10; i++)
	{
		for(j = 0; j <= buck[i]-1; j++)
		{
			a[k++] = bucket[i][j];
		}
	}

	printf("\n After sorting 8 numbers are: ");
	for(i = 0; i <= 7; i++)
	{
		printf(" %d ", a[i]);
	}

	getch();
}