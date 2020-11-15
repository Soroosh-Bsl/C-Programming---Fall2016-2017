#include<stdio.h>

int main()
{
    char ramz[1000], tabdil[1000];
    int i, q = 0, num[27];

    for (i = 0; i <= 26; i++)
    {
        num[i] = 0;
    }

    scanf("%[^\n]%*c", ramz);

    for (i = 0; i <= 999; i++)
    {
        if (ramz[i] == 'a' || ramz[i] == 'A')
        {
            num[1] += 1;
            if (1%num[1] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'b' || ramz[i] == 'B')
        {
            num[2] += 1;
            if (2%num[2] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'c' || ramz[i] == 'C')
        {
            num[3] += 1;
            if (3%num[3] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'd' || ramz[i] == 'D')
        {
            num[4] += 1;
            if (4%num[4] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'e' || ramz[i] == 'E')
        {
            num[5] += 1;
            if (5%num[5] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'f' || ramz[i] == 'F')
        {
            num[6] += 1;
            if (6%num[6] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'g' || ramz[i] == 'G')
        {
            num[7] += 1;
            if (7%num[7] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'h' || ramz[i] == 'H')
        {
            num[8] += 1;
            if (8%num[8] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'i' || ramz[i] == 'I')
        {
            num[9] += 1;
            if (9%num[9] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'j' || ramz[i] == 'J')
        {
            num[10] += 1;
            if (10%num[10] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'k' || ramz[i] == 'K')
        {
            num[11] += 1;
            if (11%num[11] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'l' || ramz[i] == 'L')
        {
            num[12] += 1;
            if (12%num[12] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'm' || ramz[i] == 'M')
        {
            num[13] += 1;
            if (13%num[13] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'n' || ramz[i] == 'N')
        {
            num[14] += 1;
            if (14%num[14] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'o' || ramz[i] == 'O')
        {
            num[15] += 1;
            if (15%num[15] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'p' || ramz[i] == 'P')
        {
            num[16] += 1;
            if (16%num[16] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'q' || ramz[i] == 'Q')
        {
            num[17] += 1;
            if (17%num[17] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'r' || ramz[i] == 'R')
        {
            num[18] += 1;
            if (18%num[18] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 's' || ramz[i] == 'S')
        {
            num[19] += 1;
            if (19%num[19] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 't' || ramz[i] == 'T')
        {
            num[20] += 1;
            if (20%num[20] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }

        else if (ramz[i] == 'u' || ramz[i] == 'U')
        {
            num[21] += 1;
            if (21%num[21] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }

        else if (ramz[i] == 'v' || ramz[i] == 'V')
        {
            num[22] += 1;
            if (22%num[22] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
       else if (ramz[i] == 'w' || ramz[i] == 'W')
        {
            num[23] += 1;
            if (23%num[23] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
       else if (ramz[i] == 'x' || ramz[i] == 'X')
        {
            num[24] += 1;
            if (24%num[24] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'y' || ramz[i] == 'Y')
        {
            num[25] += 1;
            if (25%num[25] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else if (ramz[i] == 'z' || ramz[i] == 'Z')
        {
            num[26] += 1;
            if (26%num[26] == 0)
            {
                tabdil[q] = ramz[i];
                q++;
            }
        }
        else
        {
            tabdil[q] = ramz[i];
            q++;
        }

    }

    printf("%s", tabdil);
}

