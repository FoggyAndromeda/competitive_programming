#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<vector<int>> dp(n, vector<int>(2, 1));
    dp[0][1] = 0;
    dp[1][0] += (a[1] > a[0]);
    for (int i = 2; i < n; ++i)
    {
        if (a[i] > a[i - 1])
        {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = dp[i - 1][1] + 1;
        }
        if (a[i] > a[i - 2])
        {
            dp[i][1] = max(dp[i][1], dp[i - 2][0] + 1);
        }
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
        ans = max(ans, max(dp[i][0], dp[i][1]));
    cout << ans << '\n';
}