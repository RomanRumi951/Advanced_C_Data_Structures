/* Write a program to implement bucket sorting. */

#include <stdio.h>
#include <conio.h>

void main()
{
	int bucket [10][10] = {0}, a[8] = {0}, i = 0, j = 0, k = 0, max = 0, temp = 0, count[10] = {0};
	clrscr();

	/* INPUT VALUES OF ORIGINAL ARRAY */
	printf("\n Enter 8 numbers: ");
	for(k = 0; k <= 7; k++)
	{
		scanf("%d", &a[k]);
	}

	/* FIND MAXIMUM VALUE FROM ORIGINAL ARRAY */
	max = a[0];
	for(k = 0; k <= 7; k++)
	{
		if(a[k] > max)
		{
			max = a[k];
		}
	}

	/* INSERT VALUES IN PARTICULAR BUCKET */
	for(k = 0; k <= 7; k++)
	{
		i = a[k] / 10;
		j = count[i]++;
		bucket[i][j] = a[k];
	}

	/* SORT VALUES USING INSERTION SORTING */
	for(i = 0; i <= max/10; i++)
	{
		for(j = 1; j <= count[i]-1; j++)
		{
			temp = bucket[i][j];
			for(k = j-1; k >= 0; k--)
			{
				if(bucket[i][k] > temp)
				{
					bucket[i][k+1] = bucket[i][k];
				}
				else
				{
					break;
				}
			}
			bucket[i][k+1] = temp;
		}
	}

	/* COMBINE VALUES IN ALL BUCKETS, AND STORED THESE VALUES INTO ORIGINAL ARRAY */
	k = 0;
	for(i = 0; i <= max/10; i++)
	{
		for(j = 0; j <= count[i]-1; j++)
		{
			a[k++] = bucket[i][j];
		}
	}

	/* OUTPUT VALUES OF ORIGINAL ARRAY */
	printf("\n After sorting 8 numbers are: ");
	for(k = 0; k <= 7; k++)
	{
		printf(" %d ", a[k]);
	}

	getch();
}