#include <stdio.h>
#include <conio.h>
#include <string.h>

void main()
{
	char x[50] = " ";
	clrscr();
	printf("\nInput a string : ");
	scanf("%s",x);
	if(strcmpi(x , strrev(x)) == 0)
	{
		printf("\n%s is palindrome string");
	}

	else
	{

		printf("\n%s is not palindrome string");
	}
	getch();


}