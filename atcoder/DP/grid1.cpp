#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const int mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int h, w;
    cin >> h >> w;
    vector<string> mp(h);
    for (auto &s : mp)
        cin >> s;
    vector<vector<i64>> dp(h + 1, vector<i64>(w + 1, 0ll));
    dp[1][1] = 1;
    for (int i = 1; i <= h; ++i)
    {
        for (int j = 1; j <= w; ++j)
        {
            if (i * j == 1)
                continue;
            dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % mod;
            if (mp[i - 1][j - 1] == '#')
                dp[i][j] = 0;
        }
    }
    cout << dp[h][w] << '\n';
}