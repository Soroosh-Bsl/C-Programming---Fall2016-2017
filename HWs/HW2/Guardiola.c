#include <stdio.h>

int main()
{
    int i, j, k, l, n = 0, number = 0;
    scanf("%d", &n);
    for (i=1; i<= n/4; i+=1)
    {
        for (j=1; j<= n/3;  j+=1)
        {
            for (k=1; k<= n/2; k+=1)
            {
                for (l=1; l<= n/2; l+=1)
                {
                     if (i+j+k+l==n)
                     {
                         if (l>=k && k>=j && j>=i)
                         {
                             if (i+j+k>l)
                             {
                                 if (i+k+l>j)
                                 {
                                     if (i+j+l>k)
                                     {
                                         if (l+j+k>i)
                                         {
                                             number += 1;
                                         }
                                     }
                                 }
                             }
                         }
                     }
                }
            }
        }
    }
    printf("%d",  number);
}
