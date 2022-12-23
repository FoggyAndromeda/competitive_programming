#include <bits\stdc++.h>

using namespace std;

using ui64 = uint64_t;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<vector<ui64>> dp(n, vector<ui64>(k, 0));
    for (int i = 1; i < k; ++i)
        dp[0][i] = 1;
    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < k; ++j)
        {
            dp[i][0] += dp[i - 1][j];
        }
        for (int j = 1; j < k; ++j)
        {
            for (int l = 0; l < k; ++l)
            {
                dp[i][j] += dp[i - 1][l];
            }
        }
    }
    ui64 ans = 0;
    for (int i = 0; i < k; ++i)
    {
        ans += dp[n - 1][i];
    }
    cout << ans << '\n';
}