#include <bits\stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    int n;
    cin >> n;
    vector<vector<i64>> dp(n + 1, vector<i64>(n + 1, 0));
    dp[1][1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
        {
            dp[i][j] = dp[i - j][j - 1] + dp[i - j][j];
        }
    }
    i64 ans = 0;
    // for (auto line : dp)
    //{
    //  for (auto elem : line)
    //  cout << elem << ' ';
    //  cout << '\n';
    // }
    for (int i = 2; i <= n; ++i)
    {
        ans += dp[n][i];
    }
    cout << ans << '\n';
}