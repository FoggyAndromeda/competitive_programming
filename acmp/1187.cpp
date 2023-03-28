#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

template <class T = int>
struct segtree
{
    vector<T> t;
    int n;
    function<T(T, T)> f = [](T a, T b)
    {
        return __gcd(a, b);
    };

    segtree(vector<T> a)
    {
        n = a.size();
        t.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

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

    void add(int i, int d, int v = 1, int l = 0, int r = -1)
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

    void upd(int i, int a, int v = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l > r)
            return;
        if (l == r && l == i)
        {
            t[v] = a;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m)
            upd(i, a, 2 * v, l, m);
        else
            upd(i, a, 2 * v + 1, m + 1, r);
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }

    T rq(int ql, int qr, int v = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    segtree<i64> st(a);
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        char c;
        cin >> c;
        if (c == 'g')
        {
            int l, r;
            cin >> l >> r;
            cout << st.rq(l - 1, r - 1) << ' ';
        }
        else
        {
            int j, d;
            cin >> j >> d;
            st.upd(j - 1, d);
        }
    }
}