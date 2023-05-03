x#include <stdio.h>
#include <conio.h>

void main()
{
    int a[5],i, j, n, k;
    clrscr();
    printf("input any number for n::\n\n");
    scanf("%d", &n);
    printf("Input any numbers you wanted to sort::");
    for(i=0;i<=n-1;i++)
    {
	scanf("%d",&a[i]);
    }

    for(i=1;i<=n-1;i++)
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

    for(i=0;i<=n-1;i++)
    {
	printf("\n\n%d",a[i]);
    }
    getch();
}