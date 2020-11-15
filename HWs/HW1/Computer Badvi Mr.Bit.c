#include <stdio.h>
int main(void)
{
    int i=0 , j=0, g=0, k=0, q=0, y=0, f=0;
    scanf("Mr.Bit's answer is %d.\nMr.Bit's friend's answer is %d.",&j, &i);
    k=i&j;
    g=k%2;
    k=k>>1;
    g=g+ k%2;
    k=k>>1;
    g=g+ k%2;
    k=k>>1;
    g=g+ k%2;
    k=k>>1;
    g=g+ k%2;
    k=k>>1;
    g=g+ k%2;
    k=k>>1;
    g=g+ k%2;
    k=k>>1;
    g=g+ k%2;
    y=i|j;
    f=y%2;
    y=y>>1;
    f=f+y%2;
    y=y>>1;
    f=f+y%2;
    y=y>>1;
    f=f+y%2;
    y=y>>1;
    f=f+y%2;
    y=y>>1;
    f=f+y%2;
    y=y>>1;
    f=f+y%2;
    y=y>>1;
    f=f+y%2;
    q=f-g;
    printf("There are %d bit difference(s) between these numbers.", q);
    return 0;
}
