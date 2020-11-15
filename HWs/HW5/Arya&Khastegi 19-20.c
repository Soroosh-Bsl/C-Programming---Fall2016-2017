 #include <stdio.h>

 int main()
 {
     long long flag = 0, gheymat= 0, i = 0, k = 0, m = 0, n = 0, temp = 0, q = 0, ja[500][500], gnahaei[1000], gheymati[500], min = 0, tool = 0, arz = 0, toolnah[1000], arznah[1000];
     scanf("%d %d %d", &n, &m, &k);
     for (i = 0; i <= k - 1; i++)
     {
         scanf("%lld", &gheymati[i]);
     }
     if (n == 0 && m == 0)
     {
         printf("0 0 0");
         return;
     }
     for (i = 0; i <=999; i++)
     {
        gnahaei[i] = -1;
     }
    for (i = n - 1; i >= 0; i--)
    {
        for (k = m - 1; k >= 0; k--)
        {
            scanf("%lld", &ja[i][k]);
        }
    }
    for (i = 0; i<= n - 1; i ++)
    {
        flag = 0;
        gheymat = 0;
        for (k = 0; k <= m -1; k++)
        {
            if (ja[i][k] != -1)
            {
                if (ja[i][k] != 0)
                {
                    temp = ja[i][k];
                    gheymat += gheymati[temp - 1];
                }
            }
            else if (flag == 0 && ja[i][k] == -1)
            {
                flag = 1;
                gnahaei[q] = gheymat;
                toolnah[q] = n - i;
                arznah[q] = m - (k);
                q++;
                gheymat = 0;
            }
            if (flag == 1 && ja[i][k] == -1)
            {
                gheymat = 0;
                toolnah[q] = n - i;
                arznah[q] = m - (k);
            }
            if (flag == 1 && k == m - 1)
            {
                gnahaei[q] = gheymat;
                q++;
               gheymat = 0;
            }
        }
    }

    min = gnahaei[0];
    tool = toolnah[0];
    arz = arznah[0];
    for (i = 0; gnahaei[i] >= 0; i++)
    {
        if (gnahaei[i] < min)
        {
            min = gnahaei[i];
            tool = toolnah[i];
            arz = arznah[i];
        }
    }
    printf("%lld %lld %lld", min, arz, tool);
}

