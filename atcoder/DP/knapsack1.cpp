#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    i64 w, n;
    cin >> n >> w;
    vector<i64> weights(n), values(n);
    for (i64 i = 0; i < n; ++i)
        cin >> weights[i] >> values[i];
    vector<vector<i64>> dp(n, vector<i64>(w + 1, 0));
    for (i64 i = 0; i <= w; ++i)
        if (i >= weights[0])
            dp[0][i] = values[0];
    for (i64 i = 1; i < n; ++i)
        for (i64 j = 0; j <= w; ++j)
            if (j >= weights[i])
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i]] + values[i]);
            else
                dp[i][j] = dp[i - 1][j];
    cout << dp[n - 1][w] << '\n';
}
