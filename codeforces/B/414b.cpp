#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const i64 mod = 1e9 + 7;

int main()
{
    i64 n, k;
    cin >> n >> k;
    vector<vector<i64>> dp(k, vector<i64>(n + 1, 0));
    for (i64 i = 1; i < n + 1; ++i)
        dp[0][i] = 1;
    for (i64 i = 0; i < k - 1; ++i)
        for (i64 j = 1; j < n + 1; ++j)
            for (i64 k = 1; k * j < n + 1; ++k)
                dp[i + 1][k * j] = (0ll + dp[i + 1][k * j] + dp[i][j]) % mod;
    i64 ans = 0;
    for (i64 i = 0; i < n + 1; ++i)
        ans = (0ll + dp[k - 1][i] + ans) % mod;
    cout << ans << '\n';
}