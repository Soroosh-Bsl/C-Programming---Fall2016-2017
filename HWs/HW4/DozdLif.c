#include <stdio.h>

int x, y;

int karagah()
{
	char move;
	scanf(" %c", &move);
	if (move == 'S')
	    return 0;
	karagah();
	if (move == 'L')
	    x -=1;
	if (move == 'R')
	    x +=1;
	if (move == 'U')
	    y +=1;
	 if (move == 'D')
	    y -=1;
	 printf(" -> (%d, %d)", x, y);
}

int main()
{
	scanf("%d %d", &x, &y);
	printf("(%d, %d)", x, y);
	karagah();
}
