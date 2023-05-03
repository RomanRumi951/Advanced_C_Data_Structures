#include <stdio.h>
#include <conio.h>

void main()
{
	int num, x, y, z;
	clrscr();
	printf("\n\nType any three digit number : ");
	scanf("%d ", &num);
	x = num%10;
	num = num/10;
	y = num%10;
	num = num/10;
	z = num%10;
	num = num/10;
	scanf("%d %d %d",&x, &y, &z);
	printf("\n\nFirst number = %d", z);
	printf("\n\nSecond number = %d",y);
	printf("\n\nThird number = %d",x);
	getch();



}