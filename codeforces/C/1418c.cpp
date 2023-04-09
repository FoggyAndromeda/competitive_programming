#include <bits/stdc++.h>

using namespace std;

const int INF = 1e6;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    /*
    here comes dp
    dp[i][0] - friend takes out 1 boss
    dp[i][1] - friend takes out 2 bosses
    dp[i][2] - player takes out 1 boss
    dp[i][3] - player takes out 2 bosses
    */

    // vector<vector<int>> dp(n, vector<int>(4, INF));
    // dp[0][0] = a[0];
    // for (int i = 1; i < n; ++i)
    // {
    //     dp[i][0] = min(dp[i - 1][2], dp[i - 1][3]) + a[i];
    //     dp[i][1] = dp[i - 1][0] + a[i];
    //     dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
    //     dp[i][3] = dp[i - 1][2];
    // }

    vector<int> prev(4, INF), now(4, INF);
    prev[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        now[0] = min(prev[2], prev[3]) + a[i];
        now[1] = prev[0] + a[i];
        now[2] = min(prev[0], prev[1]);
        now[3] = prev[2];
        prev = now;
    }
    cout << *min_element(prev.begin(), prev.end()) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}