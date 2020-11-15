#include <stdio.h>
int main ()
{
    int k, n, x, c, t;
    scanf("%d", &k);
    if (k<=9)
    {
        printf("%d", k);
    }
    else if (k>9 && k<=189)
    {
        t=k-9;
        c=t%2;
        if (c==1)
        {
            t=(t+1)/2;
            n=9+t;
            x=(n-n%10)/10;
            printf("%d", x);
        }
        else
        {
            t=t/2;
            n=9+t;
            x=n%10;
            printf("%d", x);
        }
    }
    else if (k>189 && k<=2889)
    {
        t=k-189;
        c=t%3;
        if (c==1)
        {
            t=(t+2)/3;
            n=99+t;
            x=(n-n%100)/100;
            printf("%d", x);
        }
        else if (c==2)
        {
            t=(t+1)/3;
            n=99+t;
            x=(x%100)/10;
            printf("%d", x);
        }
        else
        {
            t=t/3;
            n=99+t;
            x=n%10;
            printf("%d", x);
        }
    }
    else if (k>2889 && k<=36889)
    {
        t=k-2889;
        c=t%4;
        if (c==1)
        {
            t=(t+3)/4;
            n=999+t;
            x=(n-n%1000)/1000;
            printf("%d", x);
        }
        else if (c==2)
        {
            t=(t+2)/4;
            n=999+t;
            x=(x%1000)/100;
            printf("%d", x);
        }
        else if (c==3)
        {
            t=(t+3)/4;
            n=999+t;
            x=(x%100)/10;
            printf("%d", x);
        }
        else
        {
            t=t/4;
            n=999+t;
            x=n%10;
            printf("%d", x);
        }
    }
}
