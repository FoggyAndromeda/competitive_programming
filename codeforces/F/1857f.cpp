#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define eps 1e-10

void solve()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        ++mp[k];
    }
    int q;
    cin >> q;
    while (q-- > 0)
    {
        int x, y;
        cin >> x >> y;

        if (x * x < 4 * y)
        {
            cout << "0 ";
            continue;
        }

        long double discr = sqrtl(x * x - 4 * y);
        int d = discr;

        if (abs(discr - d) > eps)
        {
            cout << "0 ";
            continue;
        }

        if ((d + x) % 2 != 0)
        {
            cout << "0 ";
            continue;
        }

        if (d == 0)
        {
            int ans = 0;
            int j = x / 2;
            int i = x - j;
            if (i != j)
                ans += mp[i] * mp[j];
            else
                ans += mp[i] * (mp[j] - 1);
            ans >>= 1;
            cout << ans << ' ';
            continue;
        }

        int ans = 0;

        int j1 = (x + d) / 2;
        int i1 = x - j1;
        if (i1 != j1)
            ans += mp[i1] * mp[j1];
        else
            ans += mp[i1] * (mp[j1] - 1);

        int j2 = (x - d) / 2;
        int i2 = x - j2;

        if (i2 != j2)
            ans += mp[i2] * mp[j2];
        else
            ans += mp[i2] * (mp[j2] - 1);

        ans >>= 1;

        cout << ans << ' ';
    }
    cout << '\n';
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