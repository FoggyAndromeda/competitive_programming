#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve()
{
    i64 n, k;
    cin >> n >> k;
    unordered_map<i64, i64> counter;
    for (i64 i = 0; i < n; ++i)
    {
        i64 now;
        cin >> now;
        if (now % k == 0)
            continue;
        ++counter[k - (now % k)];
    }
    i64 ans = 0;
    for (auto [i, cnt] : counter)
        ans = max((cnt - 1) * k + i + 1, ans);
    cout << ans << '\n';
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