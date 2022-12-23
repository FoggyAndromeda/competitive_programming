#include <bits\stdc++.h>

using namespace std;

using ui64 = uint64_t;

int main()
{
    int n, s;
    cin >> n >> s;
    if (s & 1)
    {
        cout << "0\n";
        exit(0);
    }
    s /= 2;
    int max_sum = 9 * n;
    if (s > max_sum)
    {
        cout << "0\n";
        exit(0);
    }
    vector<vector<ui64>> dp(n, vector<ui64>(max_sum + 1));
    for (int i = 0; i < 10; ++i)
    {
        dp[0][i] = 1;
    }
    for (int i = 1; i < n; ++i)
    {
        for (int j = 0; j <= (i + 1) * 9; ++j)
        {
            for (int k = 0; k <= min(j, 9); ++k)
            {
                dp[i][j] += dp[i - 1][j - k];
            }
        }
    }
    cout << dp[n - 1][s] * dp[n - 1][s] << '\n';
}