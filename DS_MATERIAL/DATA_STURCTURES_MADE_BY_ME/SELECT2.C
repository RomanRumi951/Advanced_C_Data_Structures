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
	for(j=i+1;j<=n-1;j++)
	{
	    if(a[i] > a[j])
	    {
		k = a[i];
		a[i] = a[j];
		a[j] = k;
	    }
	}
    }

    for(i=0;i<=n-1;i++)
    {
	printf("\n\n%d",a[i]);
    }
    getch();
}