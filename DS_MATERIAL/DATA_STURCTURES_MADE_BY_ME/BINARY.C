#include <stdio.h>
#include <conio.h>

void main()
{
    int a[10], i, j, k;
    clrscr();
    printf("input sorted 10 numbers:::\n\n");
    for(i=0;i<=9;i++)
    {
	scanf("%d",&a[i]);
    }

    while(x
    {
	for(j=i+1;j<=4;j++)
	{
	    if(a[i] > a[j])
	    {
		k = a[i];
		a[i] = a[j];
		a[j] = k;
	    }
	}
    }

    for(i=0;i<=4;i++)
    {
	printf("\n\n%d",a[i]);
    }
    getch();
}