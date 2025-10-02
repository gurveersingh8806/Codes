#include <stdio.h>
int main()
{
    int t, i, j, g, h, ans = 0, y;
    for (i = 50; i > 0; --i)
    {
        for (j = i; (i * i * i + j * j * j) < 100000 && j > 0; --j)
        {
            t = i * i * i + j * j * j;

            for (g = 50; g > 0; --g)
            {
                for (h = g; h > 0 && (g * g * g + h * h * h) < 100000; --h)
                {
                    y = g * g * g + h * h * h;
                    if (i == g && j == h)
                        continue;
                    if (i == h && j == g)
                        continue;

                    if (t == y)
                    {
                        ans = t;
                        break;
                    }
                }
                if (ans != 0)
                    break;
            }

            if (ans != 0)
                break;
        }
        if (ans != 0)
            break;
    }
    printf("Largest Ramanujan number:%d\n", ans);
    printf("Numbers are %d,%d and %d,%d", i, j, g, h);
}