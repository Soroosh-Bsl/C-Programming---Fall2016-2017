#include <stdio.h>

int isprime(int n)
{
	int i = 0;
	if (n==1)
	{
		return 0;
	}
	else
	{
		for (i = 2; i<= sqrt(n); i +=1)
		{
			if (n%i == 0)
			{
				return 0;
			}
		}
		return 1;
	}
}
int lprimen(int n)
{
	int i = 0, m = 0, x = 0;
	for (i = 2; i < n; i += 1)
	{
		x = isprime(i);
		if ( x == 1)
		{
			m += 1;
		}
	}
	return m;
}
int maghsumprime(int n)
{
	int i = 0, g = 0, q = 0;
	q = n;
    for (i=2; i<= q/2; i +=1)
    {
        if (n%i == 0)
        {
            g += 1;
            while (n%i == 0)
            {
                n = n/i;
            }
        }
    }
    return g;
}
int main()
{
	int n = 0, x = 0, i = 0, is = 0, g = 0, q = 0;
	scanf("%d", &n);
	for (i =1; i<=n; i +=1)
	{
		scanf("%d", &x);
		is = isprime(x);
		if (is == 1)
		{
			g += lprimen(x);
		}
		else
		{
			g += maghsumprime(x);
		}
	}
	q = isprime(g);
	if (q==1)
	{
		g -= lprimen(g);
	}
	else
	{
		g -= maghsumprime(g);
	}
	printf("%d", g);
}

