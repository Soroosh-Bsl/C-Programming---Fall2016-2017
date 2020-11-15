#include<stdio.h>

long long mag = 0;

int isPrime(long long n)
{
    long long i = 0;
    for (i=2; i * i <= n + 1; i +=1)
    {
        if (n%i == 0)
        {
            mag = i;
            return 0;
        }
    }
    return 1;
}

int tag(long long a, long long b)
{
    long long maghsum = 0;
    if (a == 0)
        return 0;
    if (a == 1)
        return 1;
    if (a == 2)
    {
        if (((b * b - 1)/8)%2 == 0)
            return 1;
        else
            return -1;
    }
    if (isPrime(a) == 1 )
    {
        if (((a-1) * (b-1)/4)%2 == 0)
            return tag(b%a,a);
        else
            return -1 * tag(b%a,a);
    }
    else
    {
        maghsum = mag;
        return tag(maghsum, b) * tag(a/maghsum, b);
    }
}


int main()
{
    long n =0, i = 0;
    long long a = 0, b = 0;
    scanf("%ld", &n);
    for (i = 1; i <= n; i +=1)
    {
        scanf("%lld %lld", &a, &b);
        printf("%d\n", tag(a%b,b));
    }
}

