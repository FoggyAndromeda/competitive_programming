#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    i64 n;
    cin >> n;
    vector<i64> cnt(100'001);
    for (i64 i = 0; i < n; ++i)
    {
        i64 a;
        cin >> a;
        ++cnt[a];
    }
    vector<i64> dp(100'004, 0);
    for (i64 i = 100'000; i > 0; --i)
    {
        dp[i] = max(dp[i + 2], dp[i + 3]) + cnt[i] * i;
    }
    dp[0] = *max_element(dp.begin(), dp.end());
    cout << dp[0] << '\n';
}