#include <stdio.h>

int main()
{
    int tProject = 0, tNotTired = 0, tNotTired2 = 0, time = 0, exit = 0, degree = 0, min = 0, hour = 0, nahar = 0, i;
    char type = 'q';
    while (exit==0 && scanf( " %c %d", &type, &degree) == 2)
    {
        if (type =='k')
        {
            tProject=40 + (degree-1)*4;
        }
        else if (type =='c')
        {
            tProject=10 + (degree-1)*3;
        }
        tNotTired += tProject;
        time += tProject;
        if (tNotTired > 90)
        {
            time += 10;
            tNotTired = tProject;
            if ((time - tProject - 10 <= 570 && time - tProject - 10 > 390) || (time - tProject - 10 < 300))
            {
                min = (time - tProject)%60;
                hour = 7 + (time - tProject - min)/60;
                printf("%.2d:%.2d\n", hour, min);
            }
            else if (time - tProject - 10 <= 390 && time - tProject - 10 >= 300)
            {
                if (nahar == 0)
                {
                    nahar = 1;
                    time = time - 10 +45;
                    min = (time - tProject)%60;
                    hour = 7 + (time - tProject - min)/60;
                    printf("%.2d:%.2d\n", hour, min);
                }
            }
            else if (time - tProject > 570)
            {
                printf("please try tomorrow\n");
                exit = 1;
            }
        }
        else if ( tNotTired <= 90)
        {
            if ((time - tProject <= 570 && time - tProject > 390) || (time - tProject < 300))
            {
                min = (time - tProject)%60;
                hour = 7 + (time - tProject - min)/60;
                printf("%.2d:%.2d\n", hour, min);
            }
            else if (time - tProject <= 390 && time - tProject >= 300)
            {
                if (time > 390)
                {
                    if (nahar == 0)
                    {
                        nahar = 1;
                        time += 45;
                        min = (time - tProject)%60;
                        hour = 7 + (time - tProject - min)/60;
                        printf("%.2d:%.2d\n", hour, min);
                    }
                    else
                    {
                        min = (time - tProject)%60;
                        hour = 7 + (time - tProject - min)/60;
                        printf("%.2d:%.2d\n", hour, min);
                    }
                }
                else
                {
                   min = (time - tProject)%60;
                   hour = 7 + (time - tProject - min)/60;
                   printf("%.2d:%.2d\n", hour, min);
                }

            }
            else if (time - tProject > 570)
            {
                printf("please try tomorrow\n");
                exit = 1;
            }
        }
    }
    while (scanf(" %c %d", &type, &degree)== 2)
    {
        printf("please try tomorrow\n");
    }
}
