#include <stdio.h>
 
int main()
{
    char asghar2[1000], behrooz2[1000];
    int i, j;
 
    scanf("%[^\n]%*c", behrooz2);
    scanf("%[^\n]%*c", asghar2);
 
    for (i = 0; i <= 999; i++)
    {
        if (behrooz2[i] == '8')
        {
            if (i == 0 || behrooz2[i - 1] == ' ')
            {
                behrooz2[i] = 'b';
            }
            else if (behrooz2[i+1] == ' ' || behrooz2[i+1] == '\0')
            {
                for (j = 997; j >= i+1; j--)
                {
                    behrooz2[j + 2] = behrooz2[j];
                }
                behrooz2[i] = 'a';
                behrooz2[i + 1] = 't';
                behrooz2[i + 2] = 'e';
            }
            else
            {
                for (j = 998; j >= i+1; j--)
                {
                    behrooz2[j + 1] = behrooz2[j];
                }
                behrooz2[i] = 'o';
                behrooz2[i + 1] = 'o';
            }
        }
    }
 
    for (i = 0; i <= 999; i++)
    {
        switch (asghar2[i])
        {
            case '1' :
                asghar2[i] = 'l';
                break;
            case '9' :
                asghar2[i] = 'g';
                break;
            case '7' :
                asghar2[i] = 'r';
                break;
            case '2' :
                asghar2[i] = 'z';
                break;
        }
    }
 
    for (i = 0; i <= 999; i++)
    {
        if (asghar2[i] == 'b' && (asghar2[i - 1] == ' ' || i == 0))
        {
            asghar2[i] = '8';
        }
        else if (asghar2[i] == 'a' && asghar2[i + 1] == 't' && asghar2[i + 2] == 'e' && (asghar2[i + 3] == ' ' || asghar2[i + 3] == '\0'))
        {
            for (j = i + 1; j <= 997; j++)
            {
                asghar2[j] = asghar2[j + 2];
            }
                asghar2[i] = '8';
        }
        else if (asghar2[i] == 'o' && asghar2[i + 1] == 'o' && asghar2[i + 2] != ' ' && asghar2[i + 2] != '\0' && (asghar2[i - 1] != ' ' && i != 0))
        {
            for (j = i + 1; j <= 998; j++)
            {
                asghar2[j] = asghar2[j + 1];
            }
            asghar2[i] = '8';
        }
    }
 
    for (i = 0; i <= 1000; i++)
    {
        switch (behrooz2[i])
        {
            case 'l' :
                behrooz2[i] = '1';
                break;
            case 'g' :
                behrooz2[i] = '9';
                break;
            case 'r' :
                behrooz2[i] = '7';
                break;
            case 'z' :
                behrooz2[i] = '2';
                break;
        }
    }
 
    printf("%s\n", behrooz2);
    printf("%s", asghar2);
}
