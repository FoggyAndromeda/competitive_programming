#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 2, vector<int>(m + 2, 20));
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j)
        {
            a[i][j] = s[j - 1] - '0';
            sum += a[i][j];
        }
    }
    int min_sum_angle = 3;
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            min_sum_angle = min(min_sum_angle, a[i][j] + a[i - 1][j] + a[i][j + 1]);
            min_sum_angle = min(min_sum_angle, a[i][j] + a[i - 1][j] + a[i][j - 1]);
            min_sum_angle = min(min_sum_angle, a[i][j] + a[i + 1][j] + a[i][j + 1]);
            min_sum_angle = min(min_sum_angle, a[i][j] + a[i + 1][j] + a[i][j - 1]);
            // if (a[i][j] + a[i - 1][j] + a[i][j + 1] == 0)
            //     found_angle = true;
            // if (a[i][j] + a[i - 1][j] + a[i][j - 1] == 0)
            //     found_angle = true;
            // if (a[i][j] + a[i + 1][j] + a[i][j + 1] == 0)
            //     found_angle = true;
            // if (a[i][j] + a[i + 1][j] + a[i][j - 1] == 0)
            //     found_angle = true;
        }
    }
    if (min_sum_angle > 0)
        sum -= min_sum_angle - 1;
    cout << sum << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}