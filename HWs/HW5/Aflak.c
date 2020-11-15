#include <stdio.h>

int main()
{
    int x[101], y[101], k = 0, q = 0, i = 0, j = 0, n = 0, max = 0, counter = 1;
    double shib[200][200];
    scanf("%d", &n);
    for (i = 0; i <= n - 1; i++)
    {
       scanf("%d %d", &x[i], &y[i]);
    }
    if(n == 1)
    {
        printf("1");
        return;
    }
    for (i = 0; i <= n - 1; i++)
    {
         for (k = i + 1; k <= n - 1; k++)
        {
            if (x[k] - x[i] != 0)
                shib[i][k] = ((double)y[k] - y[i])/((double)x[k] - x[i]);
            else
                shib[i][k] = 1.7e308;
        }
        for (j = 0; j <= i - 1; j++)
        {
            if (x[i] - x[j] != 0)
                shib[i][j] = ((double)y[i] - y[j])/((double)x[i] - x[j]);
            else
                shib[i][k] = 1.7e308;
        }
    }
    for (i = 0; i <= n - 1; i++)
    {
        for (k = 0; k <= n - 1; k++)
        {
            if (k != i)
            {
                for (j = 0; j <= n - 1; j++)
                {
                    if (j != i)
                    {
                        if (shib[i][k] - shib[i][j] < 0.00001 && shib[i][k] - shib[i][j] > -0.00001)
                        {
                            counter++;
                        }
                    }
                }
                if (counter > max)
                {
                    max = counter;
                }
                counter = 1;
            }
        }
    }
    printf("%d", max);
}

