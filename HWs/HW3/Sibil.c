#include <stdio.h>
#include <math.h>

unsigned long long isprime(unsigned long long n)
{
	unsigned long long i = 0;
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
unsigned long long distance(unsigned long long n)
{
	unsigned long long i = 0, x = 0, y = 0, t = 0, u = 0;
	for (i = n; ; i -= 1)
	{
		x = isprime(i);
		if (x == 1)
		{
			t=i;
			break;
		}
	}
	for (i = n; ; i += 1)
	{
		y = isprime(i);
		if (y == 1)
		{
			u=i;
			break;
		}
	}
	if (n-t<u-n)
	{
		return n-t;
	}
	else
	{
        return u-n;
	}
}
int main ()
{
	unsigned long long n = 0,x = 0, i = 0, g = 0, t = 100000000000000;
	scanf("%llu", &n);
	for (i=1;i<=n;i += 1)
	{
		scanf("%llu", &x);
		g = distance(x);
		if (g<=t)
		{
			t = g;
		}
	}
	printf("%llu", t);
}

