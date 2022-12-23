#include <bits\stdc++.h>

using namespace std;

using ui64 = uint64_t;

int main()
{
    int n;
    cin >> n;
    vector<vector<ui64>> dp(n, vector<ui64>(4, 0));
    // 0 - red
    // 1 - blue from red
    // 2 - blue from white
    // 3 - white
    dp[0][0] = 1;
    dp[0][3] = 1;
    for (int i = 1; i < n; ++i)
    {
        dp[i][0] = dp[i - 1][2] + dp[i - 1][3];
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][3];
        dp[i][3] = dp[i - 1][0] + dp[i - 1][1];
    }
    cout << dp[n - 1][0] + dp[n - 1][3] << '\n';
}