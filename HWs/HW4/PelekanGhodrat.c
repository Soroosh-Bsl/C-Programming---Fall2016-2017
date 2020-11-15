#include<stdio.h>

int bmm(int a, int b)
{
    if (a%b == 0)
    {
        return b;
    }
    else
    {
        return bmm(b, a%b);
    }
}

int main()
{
    int n =0, i = 0, a = 0, b = 0, temp = 0;
    scanf("%d", &n);
    for (i = 1; i <= n; i +=1)
    {
        scanf("%d %d", &a, &b);
        temp = a;
        a = a < b ? b:a;
        b = temp < b ? temp:b;
        printf("%d\n", bmm(a,b));
    }
}

