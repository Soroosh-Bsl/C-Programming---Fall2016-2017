#include<stdio.h>
int main (void)
{
    int i=0, j=0, p=0, k=0;
    scanf("%d",&i);
    j=i%2;
    i=i>>1;
    p=(128*j);
    k=p|i;
    printf("%x",k);
    return 0;
}
