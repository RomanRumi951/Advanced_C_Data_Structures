#include <stdio.h>
#include <conio.h>

void main()
{
    int a[5],i, j, k;
    clrscr();
    printf("input any 5 numbers\n\n");
    for(i=0;i<=4;i++)
    {
	scanf("%d",&a[i]);
    }

    for(i=1;i<=4;i++)
    {
	k = a[i];
	for(j=i-1;j>=0;j--)
	{
	    if(k < a[j])
	    {
		a[j+1] = a[j];
	    }
	    else
	    {
		break;
	    }
	}
	a[j+1] = k;
    }

    for(i=0;i<=4;i++)
    {
	printf("\n\n%d",a[i]);
    }
    getch();
}