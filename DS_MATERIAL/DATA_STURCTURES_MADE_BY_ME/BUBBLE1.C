#include <stdio.h>
#include <conio.h>

void main()
{
    int a[5], i, j, k;
    clrscr();
    printf("input any 5 numbers\n\n");
    for(i=0;i<=4;i++)
    {
	scanf("%d",&a[i]);
    }

    for(i=0;i<=3;i++)
    {
	for(j=0;j<=3-i;j++)
	{
	    if(a[j] > a[j+1])
	    {
		k = a[j];
		a[j] = a[j+1];
		a[j+1] = k;
	    }
	}
    }

    for(i=0;i<=4;i++)
    {
	printf("\n\n%d",a[i]);
    }
    getch();
}