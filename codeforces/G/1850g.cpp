#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve()
{
    int n;
    cin >> n;
    map<int, int> h, v, d1, d2;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        ++h[x];
        ++v[y];
        ++d1[x + y];
        ++d2[x - y];
    }
    int ans = 0;

    for (auto [x, k] : h)
        ans += k * (k - 1);
    for (auto [x, k] : v)
        ans += k * (k - 1);
    for (auto [x, k] : d1)
        ans += k * (k - 1);
    for (auto [x, k] : d2)
        ans += k * (k - 1);

    cout << ans << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}