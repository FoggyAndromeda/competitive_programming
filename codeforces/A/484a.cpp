#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve()
{
    int l, r;
    cin >> l >> r;
    for (int i = 0; i < 63; ++i)
    {
        // clog << l << ' ' << ((l >> i) & 1ll) << ' ' << (l | (1ll << i)) << '\n';
        if ((((l >> i) & 1ll) == 0) && (l | (1ll << i)) <= r)
            l |= 1ll << i;
    }
    cout << l << '\n';
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