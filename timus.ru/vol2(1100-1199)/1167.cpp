#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<int> prefs(n);
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if (i == 0)
            prefs[i] = a;
        else
            prefs[i] = prefs[i - 1] + a;
    }
    int dp[k][n];
    memset(dp, 1, k * n * sizeof(int));
    // for (int i = 0; i < k; ++i)
    //     for (int j = 0; j < n; ++j)
    //         dp[i][j] = 0x7fffffff;

    for (int i = 0; i < n; ++i)
        dp[0][i] = prefs[i] * (i - prefs[i] + 1);
    for (int i = 1; i < k; ++i)
    {
        dp[i][0] = 0;
        for (int r = 1; r < n; ++r)
            for (int l = 1; l <= r; ++l)
            {
                int now_pref = prefs[r] - prefs[l - 1], len = r - l + 1;
                dp[i][r] = min(dp[i - 1][l - 1] + now_pref * (len - now_pref), dp[i][r]);
            }
    }
    cout << dp[k - 1][n - 1] << '\n';
}