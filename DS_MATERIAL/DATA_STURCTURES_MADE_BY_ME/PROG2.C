#include <stdio.h>
#include <conio.h>

void main()
{
    int a[100], i, j, k, n;
    clrscr();
    printf("Input any number for n:::\n\n");
    scanf("%d", &n);
    printf("input numbers you wanted to:::\n\n");
    for(i=0;i<=n-1;i++)
    {
	scanf("%d",&a[i]);
    }

    for(i=0;i<=n-2;i++)
    {
	for(j=0;j<=(n-2)-i;j++)
	{
	    if(a[j] > a[j+1])
	    {
		k = a[j];
		a[j] = a[j+1];
		a[j+1] = k;
	    }
	}
    }

    for(i=0;i<=n-1;i++)
    {
	printf("\n\n%d",a[i]);
    }
    getch();
}