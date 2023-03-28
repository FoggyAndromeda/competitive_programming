#include <bits/stdc++.h>

using namespace std;

template <class T>
class segtree
{
    vector<T> t;
    int n;
    vector<function<int(int, int)>> f = {
        [](int a, int b)
        {
            return a | b;
        },
        [](int a, int b)
        {
            return a ^ b;
        }};

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
        t[v] = f[__lg(v) % 2 == __lg(n) % 2](t[2 * v], t[2 * v + 1]);
    }

public:
    segtree(vector<T> a)
    {
        n = a.size();
        t.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    segtree(int k = 100'001)
    {
        n = k;
        t.assign(4 * n, 0);
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
        t[v] = f[__lg(v) % 2 == __lg(n) % 2](t[2 * v], t[2 * v + 1]);
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
        t[v] = f[__lg(v) % 2 == __lg(n) % 2](t[2 * v], t[2 * v + 1]);
    }

    T rq(int ql, int qr, int v = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (ql > qr)
            return 0;
        if (ql == l && qr == r)
            return t[v];
        int m = (l + r) >> 1;

        if (qr <= m)
            return rq(ql, qr, 2 * v, l, m);
        if (m + 1 <= ql)
            return rq(ql, qr, 2 * v + 1, m + 1, r);

        return f[__lg(v) % 2 == __lg(n) % 2](rq(ql, m, 2 * v, l, m), rq(m + 1, qr, 2 * v + 1, m + 1, r));
    }

    void log()
    {
        clog << "->TREE LOG\n";
        for (int i = 0; i <= __lg(n); ++i)
        {
            for (int j = 1 << i; j < 1 << (i + 1); ++j)
                clog << t[j] << ' ';
            clog << '\n';
        }
        clog << "TREE LOG->\n";
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(1 << n);
    for (int i = 0; i < (1 << n); ++i)
        cin >> a[i];
    segtree<int> st(a);
    // st.log();
    for (int i = 0; i < m; ++i)
    {
        int j, d;
        cin >> j >> d;
        st.upd(j - 1, d);
        cout << st.rq(0, (1 << n) - 1) << '\n';
        // st.log();
    }
}