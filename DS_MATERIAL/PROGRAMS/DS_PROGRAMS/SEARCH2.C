/* Write a program to perform linear (sequential) search in sorted list. */
#include <stdio.h>
#include <conio.h>

void main()
{
	int arr[10] = {21,22,23,29,33,45,55,67,89,99}, i, num;
	clrscr();
	printf("Enter number: ");
	scanf("%d", &num);
	for(i = 0; i <= 9; i++)
	{
		if(arr[9] < num || arr[i] >= num)
		{
			if(arr[i] == num)
			{
				printf("\nFound");
			}
			else
			{
				printf("\nNOT Found");
			}
			break;
		}
	}
	getch();
}