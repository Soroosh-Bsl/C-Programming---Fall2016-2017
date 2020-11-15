#include <stdio.h>

int nah1 = 0, nah2 = 0, nah3 = 0;
int a = 0, b =0, c = 0, flag = 0;
int counter = 0;
int counterz = 0;

int dabbe(int x, int y, int z, int dabbe1, int dabbe2, int dabbe3)
{

    if (counter > 100000)
        return -1;
    if (x > nah1)
    {
        if (x - (b - y) < 0)
        {
            y += x;
            x = 0;
        }
        else
        {
            x -= (b - y);
            y = b;
        }
        if (flag)
        {
            printf("dabbe %d -> dabbe %d\n", dabbe1, dabbe2);
            printf("%d %d %d\n", x, y, z);
        }
        counter += 1;
        if (x == nah1 && y == nah2 && z == nah3)
            return counter;
        if (y - (c - z) < 0)
        {
            z += y;
            y = 0;
        }
        else
        {
        y -= (c - z);
        z = c;
        }
        if (flag)
        {
            printf("dabbe %d -> dabbe %d\n", dabbe2, dabbe3);
            printf("%d %d %d\n", x, y, z);
        }
        counter += 1;
        if (x == nah1 && y == nah2 && z == nah3)
            return counter;
}
else if ( y > nah2)
{
    y -= (c - z);
    z = c;
    if (flag)
    {
        printf("dabbe %d -> dabbe %d\n", dabbe2, dabbe3);
        printf("%d %d %d\n", x, y, z);
    }
    counter += 1;
    if (x == nah1 && y == nah2 && z == nah3)
        return counter;
}

else
    return -1;

if (x < nah1)
{
    if (z - (a - x) < 0)
    {
        x += z;
        z = 0;
    }
    else
    {
        z -= (a - x);
        x = a;
    }
    if (flag)
    {
        printf("dabbe %d -> dabbe %d\n", dabbe3, dabbe1);
        printf("%d %d %d\n", x, y, z);
    }
    counter += 1;
    if (x == nah1 && y == nah2 && z == nah3)
        return counter;
    dabbe(x, y, z, dabbe1, dabbe2, dabbe3);
}
else if (y < nah2)
{
    if (x - (b - y) < 0)
    {
        y += x;
        z = x;
    }
    else
    {
        x -= (b - y);
        y = b;
    }
    if (flag)
    {
        printf("dabbe %d -> dabbe %d\n", dabbe1, dabbe2);
        printf("%d %d %d\n", x, y, z);
    }
    counter += 1;
    if (x == nah1 && y == nah2 && z == nah3)
        return counter;
    dabbe(x, y, z, dabbe1, dabbe2, dabbe3);
}
else
    dabbe(x, y, z, dabbe1, dabbe2, dabbe3);
}

int dabbez(int x, int y, int z, int dabbe1, int dabbe2, int dabbe3)
{
    if (counterz > 100000)
        return -1;
    if (x > nah1)
    {
        if (x - (c - z) < 0)
        {
            z += x;
            x = 0;
        }
        else
        {
            x -= (c - z);
            z = c;
        }
        if (flag)
        {
            printf("dabbe %d -> dabbe %d\n", dabbe1, dabbe3);
            printf("%d %d %d\n", x, y, z);
        }
        counterz += 1;
        if (x == nah1 && y == nah2 && z == nah3)
            return counterz;
        if (z - (b - y) < 0)
        {
            y += z;
            z = 0;
        }
        else
        {
            z -= (b - y);
            y = b;
        }
        if (flag)
        {
            printf("dabbe %d -> dabbe %d\n", dabbe3, dabbe2);
            printf("%d %d %d\n", x, y, z);
        }
    counterz += 1;
    if (x == nah1 && y == nah2 && z == nah3)
        return counterz;
}
else if (z > nah3)
{
    z -= (b - y);
    y = b;
    if (flag)
    {
        printf("dabbe %d -> dabbe %d\n", dabbe3, dabbe2);
        printf("%d %d %d\n", x, y, z);
    }
    counterz += 1;
    if (x == nah1 && y == nah2 && z == nah3)
        return counterz;
}
else
{
    return -1;
}
if (x < nah1)
{
    if (b - (a - x) < 0)
    {
        x += y;
        y = 0;
    }
    else
    {
        y -= (a - x);
        x = a;
    }
    if (flag)
    {
        printf("dabbe %d -> dabbe %d\n", dabbe2, dabbe1);
        printf("%d %d %d\n", x, y, z);
    }
    counterz += 1;
    if (x == nah1 && y == nah2 && z == nah3)
        return counterz;
    dabbez(x, y, z, dabbe1, dabbe2, dabbe3);
}

else if (z < nah3)
{
    if (x - (c - z) < 0)
    {
        z += x;
        x = 0;
    }
    else
    {
        x -= (c - z);
        z = c;
    }
    if (flag)
    {
        printf("dabbe %d -> dabbe %d\n", dabbe1, dabbe3);
        printf("%d %d %d\n", x, y, z);
    }
    counterz += 1;
    if (x == nah1 && y == nah2 && z == nah3)
        return counterz;
    dabbez(x, y, z, dabbe1, dabbe2, dabbe3);
}
 else
    dabbez(x, y, z, dabbe1, dabbe2, dabbe3);
}

int main()
{
    int x1, x2, x3 = 0, x4 = 0, xx = 0, yy = 0, zz = 0, xxx = 0, yyy = 0, zzz = 0, result = 0;
    scanf("%d %d %d", &a, &b, &c);
    scanf("%d %d %d", &nah1, &nah2, &nah3);

        if (nah1 == nah1 + nah2 + nah3)
    {
        printf("0");
        return;
    }


    x1 = dabbe(nah1 + nah2 + nah3, 0, 0,1, 2, 3);
    x2 = dabbez(nah1 + nah2 + nah3, 0, 0, 1, 2, 3);

    counter = counterz = 0;

    if (nah1 + nah2 + nah3 - b < 0)
        {
            xx = 0;
            yy = nah1 + nah2 + nah3;
        }

    else
        {
            xx = nah1 + nah2 + nah3 - b;
            yy = b;
        }

    if (nah1 + nah2 + nah3 - c < 0)
        {
            zzz = nah1 + nah2 + nah3;
            xxx = 0;
        }

    else
        {
            xxx = nah1 + nah2 + nah3 - c;
            zzz = c;
        }

    x3 = dabbez(xx, yy, zz, 1, 2, 3) + 1;
    x4 = dabbe(xxx, yyy, zzz, 1, 2, 3) + 1;

    counter = counterz = 0;

//    printf("%d\n%d\n%d\n%d\n", x1, x2, x3, x4);

    if (x1 > 0 && (x1 <= x2 || x2 <= 0) && (x1 <= x3 || x3 <= 0) && (x1 <= x4 || x4 <= 0))
        result = x1;
    if (x2 > 0 && (x2 <= x1 || x1 <= 0) && (x2 <= x3 || x3 <= 0) && (x2 <= x4 || x4 <= 0))
        result = x2;
    if (x3 > 0 && (x3 <= x2 || x2 <= 0) && (x3 <= x2 || x2 <= 0) && (x3 <= x4 || x4 <= 0))
        result = x3;
    if (x4 > 0 && (x4 <= x2 || x2 <= 0) && (x4 <= x3 || x3 <= 0) && (x4 <= x1 || x1 <= 0))
        result = x4;

    printf("%d\n", result);

    counter = counterz = 0;

    flag = 1;
    if (result == x1)
        dabbe(nah1 + nah2 + nah3, 0, 0,1, 2, 3);
    else if (result == x2)
        dabbez(nah1 + nah2 + nah3, 0, 0, 1, 2, 3);
    else if (result == x3)
    {
        printf("dabbe 1 -> dabbe 2\n%d %d %d\n", xx, yy, zz);
        dabbez(xx, yy, zz, 1, 2, 3);
    }
    else
    {
        printf("dabbe 1 -> dabbe 3\n%d %d %d\n", xxx, yyy, zzz);
        dabbe(xxx, yyy, zzz, 1, 2, 3);
    }
    }

