#include <bits/stdc++.h>

using namespace std;
const int INF = 0x7fffffff;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    for (int i = 0; i < n; ++i)
        cin >> h[i];
    vector<int> dp(n, INF);
    dp[0] = 0;
    for (int i = 1; i < n; ++i)
        for (int j = 0; j <= k && i >= j; ++j)
            dp[i] = min(dp[i - j] + abs(h[i] - h[i - j]), dp[i]);
    cout << dp[n - 1] << '\n';
}