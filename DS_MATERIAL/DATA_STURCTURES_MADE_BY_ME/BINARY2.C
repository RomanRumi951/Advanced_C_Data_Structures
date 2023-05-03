#include <stdio.h>
#include <conio.h>

void main()
{
	int a[10], i=0, lower=0, upper=9, mid=0, num=0, found=0;
	clrscr();
	printf("\nInput 10 numbers:::");
	for(i=0;i<=9;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nInput a number to be searched:::");
	scanf("%d",&num);
	while(lower<=upper)
	{
		mid = (lower+upper)/2;
		if(num == a[mid])
		{
			found = 1;
			break;
		}
		else if(num<a[mid])
		{
			upper=mid-1;
		}
		else
		{
			lower=mid+1;
		}



	}
	if(found==1)
	{
		printf("\n\nNumber Found:::");
	}
	else
	{
		printf("\n\nNumber Not Found:::");
	}


	getch();
}