#include <stdio.h>

long long counter = 0, number = 0, tavan = 1, n = 0;


long long fact(int n)
{
    if (n == 1)
        return 1;
    return n*fact(n-1);
}
int bit(int q)
{
    int x = 0, i =0;
    if (q==0)
        return 0;
    if (q==1)
        return 1;
    for (i = 1; q!=0; i ++)
    {
        x += q%2;
        q /= 2;
    }
    return x;
}

int shatranj(int satr, int tool, int arz, int nsbit)
{
    int x = 0, y = 0, nxbit = 0, nybit = 0;
    if (arz == 0)
    {
        if (number = (tool * tool) /2)
        {
            counter += 1;
        }
        return;
    }


    while (x < tavan)
        {
            y = 0;
            nxbit = bit(x);
            if (nsbit + nxbit <= tool)
                {
                    int satr1 = 0, satr2 = 0, satrf = 0, mog = 0;
                    satr1 = satr;
                    satr2 = satr;
                    satr1 >>= 1;
                    satr2 <<= 1;
                    satrf = satr1 | satr2;
                    mog = satrf ^ x;
                    if (mog - x == satrf)
                    {
                        number += nxbit;
                        while (y < tavan)
                        {
                            nybit = bit(y);
                            if(nxbit + nybit == tool)
                            {
                                int satr1 = 0, satr2 = 0, satrf = 0, mog = 0;
                                satr1 = x;
                                satr2 = x;
                                satr1 >>= 1;
                                satr2 <<= 1;
                                satrf = satr1 | satr2;
                                mog = satrf ^ y;
                                if (mog - y == satrf)
                                {
                                    number += nybit;
                                    shatranj(y, tool, arz - 2, nybit);
                                    number -= nybit;
                                }
                            }
                            ++y;
                        }
                        number -= nxbit;
                    }
                }
            ++x;
        }
    return;
}

int main()
{
    int i = 0;
    long long j =0;
    scanf("%d", &n);
    printf("%d\n", ((n+n%2)/2) * n);
    for (i = 1; i <= n; i++)
        tavan *= 2;
    if(n == 1)
    {
        printf("1");
        return;
    }
    if (n%2 == 1)
        printf("2");
    else
    {
        if (n <= 8)
        {
            shatranj(0, n, n, 0);
            printf("%d", counter);

        }
        else
        {
            j = fact(n)/(fact(n/2)*fact(n/2));
            printf("%d", j * j);
        }
    }
}

