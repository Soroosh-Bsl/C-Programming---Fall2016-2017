#include <stdio.h>

int func(int n)
{
	int i = 0, sum = 0;
	for (i=1; i<=n; i +=1)
	{
		if (n%i == 0)
		{
			sum += i;
		}
	}
	return sum;
}
int gen(int n, int k)
{
	int x = 0, sum =0;
	while (n != 0)
	{
		x = n%k;
		sum += x;
		n = (n-n%k)/k;
	}
	return sum;
}
int main()
{
	int n = 0, k = 0, f = 0, g = 0, x = 0, sum = 0, i = 0;
	scanf("%d", &n);
	scanf("%d", &k);
	for (i = 1; i<=n; i +=1)
	{
		if (n%i == 0)
		{
			f = func(n/i);
			g = gen(i, k);
			x = f*g;
			sum += x;
		}
	}
	printf("%d", sum);
}

