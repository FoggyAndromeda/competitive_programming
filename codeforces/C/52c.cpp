#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int inf = 0x7fff'ffff;

template <class T, class Func>
class segtree
{
    vector<T> t;
    vector<T> d;
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
    segtree(vector<T> a)
    {
        n = a.size();
        t.assign(4 * n, f.neutral);
        d.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    T rq(int ql, int qr, int v = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (ql > qr)
            return f.neutral;
        if (ql == l && qr == r)
            return t[v];
        int m = (l + r) >> 1;

        if (qr <= m)
            return d[v] + rq(ql, qr, 2 * v, l, m);
        if (m + 1 <= ql)
            return d[v] + rq(ql, qr, 2 * v + 1, m + 1, r);

        return d[v] + f(rq(ql, m, 2 * v, l, m), rq(m + 1, qr, 2 * v + 1, m + 1, r));
    }

    void upd(int l, int r, int dl, int v = 1, int lv = 0, int rv = -1)
    {
        if (rv == -1)
            rv = n - 1;
        if (l > r)
            return;
        if (l == lv && r == rv)
        {
            // clog << "finished updating in node " << v << " out of " << t.size() << " nodes" << '\n';
            d[v] += dl;

            while (v > 0)
            {
                if (2 * v < t.size() && 2 * v + 1 < t.size() && t[2 * v] != f.neutral && t[2 * v + 1] != f.neutral)
                    t[v] = d[v] + f(t[2 * v], t[2 * v + 1]);
                else
                    t[v] += dl;
                v /= 2;
            }

            return;
        }
        int mid = (lv + rv) >> 1;
        if (mid >= r)
            upd(l, r, dl, 2 * v, lv, mid);
        else if (l > mid)
            upd(l, r, dl, 2 * v + 1, mid + 1, rv);
        else
        {
            upd(l, mid, dl, 2 * v, lv, mid);
            upd(mid + 1, r, dl, 2 * v + 1, mid + 1, rv);
        }
    }
};

struct Min
{
    int operator()(int a, int b) { return min(a, b); }
    int neutral = inf;
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    segtree<int, Min> st(a);
    int q;
    cin >> q;
    string s;
    getline(cin, s);
    while (q-- > 0)
    {
        getline(cin, s);

        int space_cnt = count(s.begin(), s.end(), ' ');
        if (space_cnt == 1)
        {
            int l, r;
            sscanf(s.c_str(), "%I64d%I64d", &l, &r);
            // clog << "RQ: " << l << ' ' << r << '\n';
            if (l <= r)
                cout << st.rq(l, r) << '\n';
            else
                cout << min(st.rq(0, r), st.rq(l, n - 1)) << '\n';
        }
        else
        {
            int l, r, d;
            sscanf(s.c_str(), "%I64d%I64d%I64d", &l, &r, &d);
            // clog << "UPD: " << l << ' ' << r << ' ' << d << '\n';
            if (l <= r)
                st.upd(l, r, d);
            else
            {
                st.upd(0, r, d);
                st.upd(l, n - 1, d);
            }
        }
        // for (int i = 0; i < n; ++i)
        // for (int j = i; j < n; ++j)
        // {
        // clog << "RQ FOR " << i << ' ' << j << ": " << st.rq(i, j) << '\n';
        // }
    }
}