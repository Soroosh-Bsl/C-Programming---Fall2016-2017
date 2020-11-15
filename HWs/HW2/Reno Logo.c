#include<stdio.h>

int main ()
{
    int a, b, x, y, i, j, k, l, m, n, h, t, s, g;
    scanf("%d%d",&a, &b);
    if (a!=b)
    {
    x=2*a-1;
    y=(x-b)/2;
    h=y-(x-2*b-1)/2;
    for (i=1;i<=y;i+=1)
    {
        s = y-(i-1);
        for (j=1;j<=s;j+=1)
        {
            printf(" ");
        }
        if (i>h)
        {
            t=1+2*(i-h-1);
            g=(x-2*s-t);
            for (l=1;l<=g/2;l+=1)
            {
                printf("*");
            }
            for (m=1;m<=t;m+=1)
            {
                printf(" ");
            }
            for (l=1;l<=g/2;l+=1)
            {
                printf("*");
            }
        printf("\n");
        }
        else
        {
            for (k=1;k<=b+2*i-2*1;k+=1)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    for (n=1;n<=b;n+=1)
    {
    printf("*");
    }
    for (n=1;n<=(x-2*b);n+=1)
    {
    printf(" ");
    }
    for (n=1;n<=b;n+=1)
    {
    printf("*");
    }
    printf("\n");
    for (i=y;i>=1;i-=1)
    {
        s = y-(i-1);
        for (j=1;j<=s;j+=1)
        {
            printf(" ");
        }
        if (i>h)
        {
              t=1+2*(i-h-1);
            g=(x-2*s-t);
            for (l=1;l<=g/2;l+=1)
            {
                printf("*");
            }
            for (m=1;m<=t;m+=1)
            {
                printf(" ");
            }
            for (l=1;l<=g/2;l+=1)
            {
                printf("*");
            }
        printf("\n");
        }
        else
        {
            for (k=1;k<=b+2*i-2*1;k+=1)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    }
    else
    {
            x=2*a-1;
    y=(x-b)/2;
    h=y-(x-2*b-1)/2;
    for (i=1;i<=y;i+=1)
    {
        s = y-(i-1);
        for (j=1;j<=s;j+=1)
        {
            printf(" ");
        }
        if (i>h)
        {
            t=1+2*(i-h-1);
            g=(x-2*s-t);
            for (l=1;l<=g/2;l+=1)
            {
                printf("*");
            }
            for (m=1;m<=t;m+=1)
            {
                printf(" ");
            }
            for (l=1;l<=g/2;l+=1)
            {
                printf("*");
            }
        printf("\n");
        }
        else
        {
            for (k=1;k<=b+2*i-2*1;k+=1)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    for (n=1;n<=b-1;n+=1)
    {
    printf("*");
    }
    for (n=1;n<=(x-2*b);n+=1)
    {
    printf(" ");
    }
    for (n=1;n<=b;n+=1)
    {
    printf("*");
    }
    printf("\n");
    for (i=y;i>=1;i-=1)
    {
        s = y-(i-1);
        for (j=1;j<=s;j+=1)
        {
            printf(" ");
        }
        if (i>h)
        {
              t=1+2*(i-h-1);
            g=(x-2*s-t);
            for (l=1;l<=g/2;l+=1)
            {
                printf("*");
            }
            for (m=1;m<=t;m+=1)
            {
                printf(" ");
            }
            for (l=1;l<=g/2;l+=1)
            {
                printf("*");
            }
        printf("\n");
        }
        else
        {
            for (k=1;k<=b+2*i-2*1;k+=1)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    }

}
