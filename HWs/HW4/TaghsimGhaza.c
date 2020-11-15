#include <stdio.h>

long long number(long long sum, long long largestNumber)
{
    if (largestNumber == 0)
        return 0;
    if (sum == 0)
        return 1;
    if (sum < 0)
        return 0;
    return number(sum, largestNumber - 1) + number(sum - largestNumber, largestNumber);
}

int main()
{
    long long sum = 0;
    scanf("%lld", &sum);
    printf("%lld",number(sum,sum));
}

