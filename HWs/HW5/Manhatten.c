#include <stdio.h>
int arr[11][11], i = 0, j = 0, counter = 0, money[185000] = {0};
unsigned long long  k =0;
int rah(int arr[][11], int index1, int index2)
{
    if (index1 == i && index2 == j)
    {
        counter += arr[index1][index2];
        money[k] = counter;
        k += 1;
        counter -= arr[index1][index2];
        return;
    }
    int x = 0;
    while (x < 2)
    {
       if (x == 0 && index2 != j)
       {
            counter += arr[index1][index2];
            rah(arr, index1, index2 + 1);
            counter -= arr[index1][index2];
       }
       else if (x == 1 && index1 != i)
       {
            counter += arr[index1][index2];
            rah(arr, index1 + 1, index2);
            counter -= arr[index1][index2];
       }
        ++x;
    }
    return;
}
unsigned long long fact(int n)
{
    if (n == 0)
        return 1;
    return n * fact(n - 1);
}
int main()
{
    int k = 0, g = 0, min = 0;
    unsigned long long halghe = 0, q = 0;
    scanf("%d %d", &i, &j);
    for (k = i; k >= 0; k--)
    {
        for (g = 0; g <= j; g++)
        {
            scanf("%d", &arr[k][g]);
        }
    }
    rah (arr, 0, 0);
    halghe = fact(i+j)/(fact(i) * fact(j));
    min = money[0];
    for (q = 0; q < halghe; q++)
    {
       if (money[q] < min)
            min = money[q];
    }
    printf("%d", min);
}

