#include <stdio.h>
int main ()
{
    int k=0, height = 0, x = 0, i = 1, g = 0, h= 0, n = 0, y=0, t = 0;
    scanf("%d", &n);
    for (i=1;i<=n;i=i+1)
    {
        scanf("%d", &height);
        h=height - x;
        if ( i == 1)
        {
            h=0;
        }
        y = k%2;
        if (y == 0)
        {
        if (h == 0)
        {
            h = g;
        }
       if (h*g<0)
        {
        k=k+1;
        }
        }
        else if ( y == 1)
        {
       if (h*g<=0)
        {
        k=k+1;
        }
        }
    g=h;
    x=height;
    }
        if (k<=1)
       {
          printf("Yes");
        }
        else
        {
       printf("No");
        }
}
