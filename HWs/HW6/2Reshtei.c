#include<stdio.h>
#include<string.h>

int main()
{
    char aval[1000], dovom[1000], temp[1000], temp2[1000];
    int i, j, k, num[10000], q = 0, min1[10000], tool[10000], max, minAval, baze, flag = 0;

    for (i = 0; i <= 9999; i++)
    {
        num[i] = 0;
    }

    for (i = 0; i <= 999; i++)
    {
        aval[i] = '\0';
        dovom[i] = '\0';
        temp[i] = '\0';
        temp2[i] = '\0';
    }

    scanf("%[^\n]%*c", aval);
    scanf("%[^\n]%*c", dovom);

    for (i = 0; i < strlen(aval); i++)
    {
//        printf("i = %d\n", i);
        for (k = 0; k < strlen(dovom); k++)
        {
            flag = 0;
            if (aval[i] == dovom[k])
            {
//                            printf("k = %d\n", k);

                num[q] = 1;
                min1[q] = i;
                tool[q] = 1;
                for (j = 1; i + j < strlen(aval) && k + j < strlen(dovom); j++)
                {
//                    printf("j = %d\n", j);
                    if (aval[i + j] == dovom[k + j])
                    {
                        num[q] += 1;
                        tool[q] = j + 1;
                    }
                    else
                    {
//                        printf("num = %d", num[q]);
                        flag = 1;
                        q++;
                        break;
                    }
                }
                if (flag != 1)
                {
                    q++;
                }
            }
        }
    }
    max = num[0];
    minAval = min1[0];
    baze = tool[0];

    for (i = 1; i <= 9999; i++)
    {
        if (num[i] > max)
        {
            max = num[i];
            minAval = min1[i];
            baze = tool[i];
        }
        else if(num[i] == max)
        {
            for (j = 0; j < baze; j++)
            {
                temp[0 + j] = aval[minAval + j];
                temp2[0 + j] = aval[min1[i] + j];
            }
                if (strcmp(temp, temp2) > 0)
                {
                    max = num[i];
                    minAval = min1[i];
                    baze = tool[i];
                }

        }
    }

    for (j = 0; j < baze; j++)
    {
        printf("%c", aval[minAval + j]);
    }
}

