#include <bits/stdc++.h>

using namespace std;

#define int int64_t

struct fenwicktree
{
    vector<int> t;
    int len;

    fenwicktree(int n)
    {
        t.assign(n + 1, 0);
        len = n;
    }

    void add(int i, int d)
    {
        for (++i; i <= len; i += i & -i)
            t[i] += d;
    }

    int pref(int i)
    {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += t[i];
        return res;
    }

    int rq(int l, int r)
    {
        if (l == 0)
            return pref(r);
        return pref(r) - pref(l - 1);
    }
};

void solve()
{
    int n;
    cin >> n;
    fenwicktree ft(n);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int now;
        cin >> now;
        --now;
        ans += ft.rq(now, n - 1);
        ft.add(now, 1);
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