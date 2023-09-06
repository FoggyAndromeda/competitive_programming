#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    /*
        if a[i] + x == b^2 and a[j] + x = c^2
        b^2 - a[i] = c^2 - a[j]
        (c - b)(c + b) = a[j] - a[i]
        if i < j, a[i] < a[j] -> b < c. let a[j] - a[i] = kl, k < l
        c - b = k and c + b = l
        c = (k + l) / 2
        b = l - (k + l) / 2

        then x = b^2 - a[i]
    */

    map<int, set<int>> cnt;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int dif = a[j] - a[i];
            int x = -1;
            for (int k = 1; k * k <= dif; ++k)
            {
                if (dif % k != 0)
                    continue;
                int l = dif / k;
                if ((k + l) % 2 != 0)
                    continue;
                int c = (k + l) >> 1;
                int x = c * c - a[j];
                if (x < 0)
                    continue;
                cnt[x].insert(i);
                cnt[x].insert(j);
                // clog << a[i] << ' ' << a[j] << ' ' << x << '\n';
            }
        }
    }
    int ans = 1;
    for (auto &[k, v] : cnt)
    {
        ans = max(ans, (int)v.size());
    }
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