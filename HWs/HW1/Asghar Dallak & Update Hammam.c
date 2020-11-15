#include<stdio.h>
int main()
{
    int D,T,r,h,g,e;
    float P;
    scanf("%d",&D);
    r=D-1;
    h=r*45;
    g=h%60;
    e=(h-g)/60;
    T=e+5;
    P=((D-1)*0.04)+3.29;
    printf("Welcome to my hammaam!\nI will rub you with kise with degree %d and this will approximately last %.2d:%.2d!\nAt the end you should give me %.2f$.\nHave fun!",D,T,g,P);
}
