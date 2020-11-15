#include <stdio.h>

int main()
{
    int n = 0, x = 0, a = 0, b = 0, c = 0, i = 0, arr[200];
    scanf("%d", &n);
    for (i = 0; i <= n - 1; i++)
    {
        scanf("%d", &x);
        if (x == 1)
        {
            scanf(" confluence %c[%c,%c]", &a, &b, &c);
            if (b < 58 && b > 47 && c < 58 && c > 47)
            {
                arr[a] = b + c -96;
            }
            else if (c < 58 && c > 47)
            {
                arr[a] = arr[b] + c - 48;
            }
            else if (b < 58 && b > 47)
            {
                arr[a] = arr[c] + b - 48;
            }
            else
            {
                arr[a]= arr[b] + arr[c];
            }
        }
        else if (x == 2)
        {
            scanf(" bifurcation [%c,%c]%c", &a, &b, &c);
            if (c < 58 && c > 47)
            {
                arr[a] = arr[b] = c - 48;
            }
            else
            {
                arr[a] = arr[b] = arr[c];
            }
        }
    }
    printf("%d", arr[122]);

}

