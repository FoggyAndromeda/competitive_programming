#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, s;
    cin >> m >> s;
    if (s == 0 && m == 1)
    {
        cout << "0 0\n";
        return 0;
    }
    if (s == 0 || s > 9 * m)
    {
        cout << "-1 -1\n";
        return 0;
    }
    int t = s;
    for (int i = m; i > 0; --i)
    {
        for (int j = i == m; j < 10; ++j)
        {
            // clog << i << ' ' << j << ' ' << t << '\n';
            if (i > 1 && t - j >= 0 && t - j <= 9 * (i - 1))
            {
                t -= j;
                cout << j;
                break;
            }
            if (i == 1 && t == j)
            {
                cout << j;
                break;
            }
        }
    }
    cout << ' ';

    t = s;
    for (int i = m; i > 0; --i)
    {
        for (int j = 9; j > -1; --j)
        {
            // clog << i << ' ' << j << ' ' << t << '\n';
            if (i > 1 && t - j >= 0 && t - j <= 10 * (i - 1) - 1)
            {
                t -= j;
                cout << j;
                break;
            }
            if (i == 1 && t == j)
            {
                cout << j;
                break;
            }
        }
    }
    cout << '\n';
}