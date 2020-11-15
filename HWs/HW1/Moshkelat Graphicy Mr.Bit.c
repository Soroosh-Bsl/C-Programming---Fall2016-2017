#include <stdio.h>
int main()
{
    int i=0 ,j=0, k=0, l=0, m=0, n=0, o=0, p=0, q=0, g=0;
    scanf("%d", &i);
    j=i%2;
    i=i>>1;
    g=i%2;
    i=i>>1;
    k=i%2;
    i=i>>1;
    l=i%2;
    i=i>>1;
    m=i%2;
    i=i>>1;
    n=i%2;
    i=i>>1;
    o=i%2;
    i=i>>1;
    p=i%2;
    q = (1-j)+j*(1-g)*(2)+j*g*(1-k)*(4)+j*g*k*(1-l)*(8)+j*g*k*l*(1-m)*(16)+j*g*k*l*m*(1-n)*(32)+j*g*k*l*m*n*(1-o)*(64)+j*g*k*l*m*n*o*(1-p)*(128);
    printf("%d", q);
    return 0;
}
