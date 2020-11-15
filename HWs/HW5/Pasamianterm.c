#include <stdio.h>

int ghad[1400], weight[1400], s[1400], degk[1400], degm[1400];

 int mini( int weight[], int n)
 {
 	int min,  minIndex, i;
 	min = weight[0];
 	for (i = 0; i <= n- 1; i++)
 	{
 		if (weight[i] < min)
 		{
 			min = weight[i];
 			minIndex = i;
 		}
 	}
 	printf("%d %d %d %d %d\n", ghad[minIndex], weight[minIndex], s[minIndex], degk[minIndex], degm[minIndex]);
 	weight[minIndex] = 2147483647 ;
 	return;
 }
 
int main()
{
    int i = 0, n = 0;
    scanf("%d", &n);
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d %d %d %d %d", &ghad[i], &weight[i], &s[i], &degk[i], &degm[i]);
    }
    for(i = 0; i <= n - 1; i++)
    {
        mini(weight, n);
    }
}
