#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; ++i)
        pref[i] = pref[i - 1] + a[i];

    vector<vector<int>> dp(k + 1, vector<int>(n, 0));
    for (int i = 1; i < k + 1; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (j < m - 1)
                continue;
            if (j == m - 1)
            {
                dp[i][j] = pref[j];
                continue;
            }
            dp[i][j] = max(dp[i][j - 1], dp[i - 1][j - m] + pref[j] - pref[j - m]);
        }
    }
    // for (auto &line : dp)
    // {
    //     for (auto elem : line)
    //         clog << elem << ' ';
    //     clog << '\n';
    // }
    cout << dp[k][n - 1] << '\n';
}