#include <stdio.h>
#include <stdlib.h>

int  n = 0, m = 0, result = 0,  k = 0;
int *radif;
int *sotun;
int *radius;
int **xyseen;
int *seenbomb;
		

int f(int enfejarID)
{
	int x = 0, y = 0, j =0;
	for (x = *(radif + enfejarID) - *(radius + enfejarID); x <= *(radif + enfejarID) + *(radius + enfejarID); x++)
		{
			for (y = *(sotun + enfejarID) - *(radius + enfejarID); y <= *(sotun + enfejarID) + *(radius + enfejarID); y++)
			{
//				printf("nx = %d\nny = %d\n", x, y);
				if (x > 0 && y > 0 && x <= m && y <= n)
				{							
					if ( xyseen[x - 1][y - 1] == 0)	
					{
//					printf("x = %d\ny = %d\n", x, y);
						result -= 1;
						xyseen[x - 1][y - 1] = 1;
						
						for (j = 0; j < k; j++)
						{
							if (x == *(radif + j) && y == *(sotun + j) && j != enfejarID)
							{
								if (*(seenbomb + j) == 0)
								{
									*(seenbomb + j) = 1;
									f(j);
								}
							}
						}
					}			
					
				}
			}
		}
}


int main()
{
	int i = 0;
	int targetn = 0, targetm = 0, flag = 0, enfejarID = 0, j = 0, x = 0, y = 0;
	
	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &k);
	
	xyseen = (int**)calloc(m + 1, sizeof(int *));
	for (i = 0; i < m; i++)
	{
		*(xyseen + i) = (int*)calloc(n + 1, sizeof(int));	
	}
	radif = (int*)calloc(k, sizeof(int));
	sotun = (int*)calloc(k, sizeof(int));
	radius = (int*)calloc(k, sizeof(int));
	seenbomb = (int*)calloc(k, sizeof(int));
	
	for (i = 0; i < k; i++)
	{
		scanf("%d", (sotun + i));
		scanf("%d", (radif + i));
		scanf("%d", (radius + i));
	}
	
	scanf("%d", &targetn);
	scanf("%d", &targetm);	
	
	for (i = 0; i < k; i++)
	{
		if (targetm == *(radif + i) && targetn == *(sotun + i))
		{
			flag = 1;
			enfejarID = i;
			break;
		}
	}
	
	result = n * m;
	
	if (flag == 0)
	{
		printf("%d", result -= 1);
		return 0;
	}
	
	else if (flag)
	{
		f(enfejarID);	
	}
	
	printf("%d", result);
}

