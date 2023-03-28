#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> trees(n);
    for (int i = 0; i < n; ++i)
        cin >> trees[i].first >> trees[i].second;
    if (n == 1)
    {
        cout << 1 << '\n';
        return 0;
    }
    vector<vector<int>> dp(n, vector<int>(3, 0));
    // dp[i][0] - no changes
    // dp[i][1] - left
    // dp[i][2] - right
    dp[0][1] = 1;
    if (trees[0].first + trees[0].second < trees[1].first - trees[1].second)
        dp[0][2] = 1;
    for (int i = 1; i < n; ++i)
    {
        dp[i][0] = max(dp[i - 1][2], max(dp[i - 1][0], dp[i - 1][1]));
        if (trees[i - 1].first < trees[i].first - trees[i].second)
            dp[i][1] = max(dp[i - 1][0], dp[i - 1][1]) + 1;
        if (trees[i - 1].first + trees[i - 1].second < trees[i].first - trees[i].second)
            dp[i][1] = max(dp[i][1], dp[i - 1][2] + 1);
        if (i == n - 1)
            dp[i][2] = dp[i][0] + 1;
        else if (trees[i].first + trees[i].second < trees[i + 1].first)
            dp[i][2] = dp[i][0] + 1;
    }
    cout << max(dp[n - 1][0], max(dp[n - 1][1], dp[n - 1][2])) << '\n';
}