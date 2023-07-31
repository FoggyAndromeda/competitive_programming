#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    int mp2[n][n];
    int mp5[n][n];

    bool have_zeroes = false;
    int zero_row = -1;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            int k;
            cin >> k;
            if (k == 0)
            {
                have_zeroes = true;
                zero_row = i;
                continue;
            }
            int t = 0, f = 0;
            while (k % 2 == 0)
            {
                ++t;
                k /= 2;
            }
            while (k % 5 == 0)
            {
                ++f;
                k /= 5;
            }
            mp2[i][j] = t;
            mp5[i][j] = f;
        }
    }
    int dp2[n][n], dp5[n][n];
    char dir2[n][n], dir5[n][n];

    dp2[0][0] = mp2[0][0];
    dp5[0][0] = mp5[0][0];

    for (int i = 1; i < n; ++i)
    {
        dp2[0][i] = dp2[0][i - 1] + mp2[0][i];
        dir2[0][i] = 'R';
    }
    for (int i = 1; i < n; ++i)
    {
        dp2[i][0] = dp2[i - 1][0] + mp2[i][0];
        dir2[i][0] = 'D';
    }
    for (int i = 1; i < n; ++i)
    {
        dp5[0][i] = dp5[0][i - 1] + mp5[0][i];
        dir5[0][i] = 'R';
    }
    for (int i = 1; i < n; ++i)
    {
        dp5[i][0] = dp5[i - 1][0] + mp5[i][0];
        dir5[i][0] = 'D';
    }

    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
        {
            if (dp2[i - 1][j] > dp2[i][j - 1])
            {
                dp2[i][j] = dp2[i][j - 1] + mp2[i][j];
                dir2[i][j] = 'R';
            }
            else
            {
                dp2[i][j] = dp2[i - 1][j] + mp2[i][j];
                dir2[i][j] = 'D';
            }
        }
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
        {
            if (dp5[i - 1][j] > dp5[i][j - 1])
            {
                dp5[i][j] = dp5[i][j - 1] + mp5[i][j];
                dir5[i][j] = 'R';
            }
            else
            {
                dp5[i][j] = dp5[i - 1][j] + mp5[i][j];
                dir5[i][j] = 'D';
            }
        }

    if (min(dp2[n - 1][n - 1], dp5[n - 1][n - 1]) > 1 && have_zeroes)
    {
        cout << "1\n";
        for (int i = 0; i < zero_row; ++i)
            cout << 'D';
        for (int i = 0; i < n - 1; ++i)
            cout << 'R';
        for (int i = zero_row + 1; i < n; ++i)
            cout << 'D';
    }

    else if (dp2[n - 1][n - 1] < dp5[n - 1][n - 1])
    {
        cout << dp2[n - 1][n - 1] << '\n';

        int x = n - 1, y = n - 1;
        string s;
        while (x + y > 0)
        {
            s.push_back(dir2[x][y]);
            if (dir2[x][y] == 'D')
                --x;
            else
                --y;
        }
        for (int i = s.size() - 1; i > -1; --i)
            cout << s[i];
    }
    else
    {
        cout << dp5[n - 1][n - 1] << '\n';

        int x = n - 1, y = n - 1;
        string s;
        while (x + y > 0)
        {
            s.push_back(dir5[x][y]);
            if (dir5[x][y] == 'D')
                --x;
            else
                --y;
        }
        for (int i = s.size() - 1; i > -1; --i)
            cout << s[i];
    }
}