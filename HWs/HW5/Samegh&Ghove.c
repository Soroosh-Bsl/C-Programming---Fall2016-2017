#include<stdio.h>
int Swap(int inputArray[], int index1, int index2)
{
    int aux = inputArray[index1];
    inputArray[index1] = inputArray[index2];
    inputArray[index2] = aux;
    return;
}


int findArgMax(int arr[], int st, int en)
{
    int maxIndex = en, i = 0;
    for(i = en; i >= st; i--)
    {
        if(arr[i] > arr[maxIndex])
        {
            maxIndex = i;
        }
    }
    return maxIndex;
}


int main()
{
    int n = 0, rad[101], makh[101], radical[101], surat[101], k = 0, i = 0, j = 0, temp = 0, counter = 0, max = 0, temp2 = 0, q = 0, makhraj = 1, sur[101], makhrajha[101], g =0, radi[101], makhloot[101];
    for (i = 0; i <= 101; i++)
    {
        surat[i] = 1;
        rad[i] = 0;
        makh[i] = 0;
        radi[i] = 0;
        radical[i] = 0;
        sur[i] = 0;
        makhloot[i] = 0;
        makhrajha[i] = 0;
    }
    scanf("%d", &n);
    for (i = 0; i <= n - 1; i++)
    {
        surat[i] = 1;
        scanf("%d %d", &rad[i], &makh[i]);
        radical[i] = rad[i] * makh[i];
        temp = radical[i];
        temp2 = radical[i];
        for (j = 2; j <= temp2; j++)
        {
            counter = 0;
            if (temp%j == 0)
            {
                while (temp%j == 0 && temp!= 1)
                {
                    counter++;
                    temp /= j;
                }
                for (k = 1; k <= ((counter - counter%2)/2); k++)
                {
                    surat[i] *= j;
                    radical[i] /= (j * j);
                }
            }
        }
        max = (surat[i] > makh[i]) ? surat[i] : makh[i];
        for (k = 2; k <= max ; k++)
        {
            if (surat[i]%k == 0 && makh[i]%k == 0 && makh[i] != 1 && surat[i] != 1)
            {
                while (surat[i]%k == 0 && makh[i]%k == 0 && makh[i] != 1 && surat[i] != 1)
                {
                    surat[i] /= k;
                    makh[i] /= k;
                }
            }
        }
    }
    for(i = n - 1; i > 0; i--)
    {
        int argMax = findArgMax(radical, 0, i);
        Swap(radical, argMax, i);
        Swap(makh, argMax, i);
        Swap(surat, argMax, i);
    }
    for(i= 0 ; i <= n - 1; i++)
    {
        if (radical[i]==radical[i + 1])
        {
            makhraj *= makh[i];
        }
        else
        {
            makhraj *= makh[i];
            for (k=i; k >= g; k--)
            {
                sur[q] += (makhraj/makh[k]) * surat[k];
            }
            radi[q] = radical[i];
            makhrajha[q] = makhraj;
            q++;
            makhraj = 1;
            g = i + 1;
        }
    }
    for (i = 0; radi[i] != 0; i ++)
    {
         max = (sur[i] > makhrajha[i]) ? sur[i] : makhrajha[i];
        for (k = 2; k <= max ; k++)
        {
            if (sur[i]%k == 0 && makhrajha[i]%k == 0 && makhrajha[i] != 1 && sur[i] != 1)
            {
                while (sur[i]%k == 0 && makhrajha[i]%k == 0 && makhrajha[i] != 1 && sur[i] != 1)
                {
                    sur[i] /= k;
                    makhrajha[i] /= k;
                }
            }
        }
    }
    for (i = 0; radi[i] != 0; i++)
    {
        makhloot[i] = sur[i]/makhrajha[i];
        sur[i] = sur[i] - (makhloot[i] * makhrajha[i]);
        printf("%d %d %d %d\n", makhloot[i], sur[i], makhrajha[i], radi[i]);
    }
}

