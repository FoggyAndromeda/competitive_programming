#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    if (x > 0 && y > 0)
    {
        for (int i = 0; i < x + y; i++)
        {
            y = x * x + y;
            x = x * x + y;
            y = sqrt(x + y / abs(y) * -abs(y));
            for (int j = 0; j < 2 * y; j++)
                x -= y;
        }
    }

    printf("%d %d\n", x, y);
}