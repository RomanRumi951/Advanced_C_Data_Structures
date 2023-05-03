#include <stdio.h>
#include <conio.h>

int main()
{
	int a[10], i=0, n, lower=0, upper=0, mid=0, num=0, found=0;
	// clrscr();
	printf("Input any number for n:::\n\n");
	scanf("%d", &n);
	printf("\nInput numbers:::");
	for(i=0;i<=n-1;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("\nInput a number to be searched:::");
	scanf("%d",&num);
	upper=n-1;
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


	// getch();
}