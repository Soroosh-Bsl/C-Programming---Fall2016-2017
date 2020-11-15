#include <stdio.h>
int main ()
{
    int n = 0, i, l,j , x = 0, y = 0, z=0, g = 0, k=0, h=0, a, b, t = 0;
    scanf ("%d", &n);
   if (n==2)
    {
    printf("3\n");
    printf("3");
    }
   else if (n==4 || n==3)
    {
    printf("6\n");
    printf("2 3");
    }
    else
   {
    for (i=1; t<n; i=i+1)
    {
        t = 1;
        x=i*(i+1)/2;
        y=x;
        for (j=2; j * j<= y;j=j+1)
        {
            g=0;
            a=x%j;
            if (a==0)
            {
                do
                {
                    x=x/j;
                    h=x%j;
                    g += 1;
                }while (h==0 && x!=1);
            }
            t *= (g+1);
        }
    }
    if (t>=n)
   {
        z=y;
        printf("%d\n", y);
        for (l=2; l<=z/2;l=l+1)
        {
            b=y%l;
            if (b==0 && y!=1)
            {
                printf("%d ", l);
                y=y/l;
                k=y%l;
                while (k==0 && y!=1)
                {
                printf("%d ", l);
                y=y/l;
                k=y%l;
                }
            }
        }
    }
    }
}
