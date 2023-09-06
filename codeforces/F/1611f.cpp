#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

template <class T, class Func>
class segtree
{
    vector<T> t;
    int n;
    Func f;

    void build(int v, int l, int r, vector<T> &a)
    {
        if (l == r)
        {
            t[v] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(2 * v, l, m, a);
        build(2 * v + 1, m + 1, r, a);
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }

public:
    segtree(vector<T> &a)
    {
        n = a.size();
        t.assign(4 * n, f.neutral);
        build(1, 0, n - 1, a);
    }

    segtree(int k = 100'001)
    {
        n = k;
        t.assign(4 * n, f.neutral);
    }

    void add(int i, T d, int v = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l == r)
        {
            t[v] += d;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m)
            add(i, d, 2 * v, l, m);
        else
            add(i, d, 2 * v + 1, m + 1, r);
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }

    T rq(int ql, int qr, int v = 1, int l = 0, int r = -1)
    {
        // clog << '\t' << ql << ' ' << qr << ' ' << l << ' ' << r << '\n';
        if (r == -1)
            r = n - 1;
        if (ql > qr || l > r)
            return f.neutral;
        if (ql == l && qr == r)
            return t[v];
        int m = (l + r) >> 1;

        if (qr <= m)
            return rq(ql, qr, 2 * v, l, m);
        if (m + 1 <= ql)
            return rq(ql, qr, 2 * v + 1, m + 1, r);

        return f(rq(ql, m, 2 * v, l, m), rq(m + 1, qr, 2 * v + 1, m + 1, r));
    }
};

struct Min
{

    int operator()(int a, int b)
    {
        return min(a, b);
    }

    int neutral = 0x7fff'ffff'ffff'ffff;
};

void solve()
{
    int n, s;
    cin >> n >> s;
    n += 1;
    vector<int> a(n);
    a[0] = 0;
    for (int i = 1; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
        a[i] += a[i - 1];

    segtree<int, Min> st(a);
    pair<int, int> ans = {-1, -1};

    for (int i = 1; i < n; ++i)
    {
        int l = i - 1, r = n;
        while (r - l > 1)
        {
            // clog << l << ' ' << r << '\n';
            int mid = (l + r) >> 1;
            if (s + st.rq(i, mid) - a[i - 1] < 0)
                r = mid;
            else
                l = mid;
        }
        // clog << i << ' ' << l << '\n';
        if (l < i)
            continue;
        if (ans.first == -1)
            ans = {i, l};
        else if (ans.second - ans.first < l - i)
            ans = {i, l};
    }
    if (ans.first != -1)
        cout << ans.first << ' ' << ans.second << '\n';
    else
        cout << "-1\n";
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