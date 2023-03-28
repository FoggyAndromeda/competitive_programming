#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

//! UNCHECKED

template <class T>
struct FenwickTree
{
    vector<T> t;
    int n;

    FenwickTree(vector<T> &a)
    {
        n = a.size() + 1;
        t.assign(n, 0);
        for (int i = 0; i < n; ++i)
            upd(i, a[i]);
    }

    FenwickTree(int l)
    {
        n = l + 1;
        t.assign(n, 0);
    }

    T pref(int i)
    {
        T res = 0;
        for (++i; i > 0; i -= i & -i)
            res = res + t[i];
        return res;
    }

    T rq(int l, int r)
    {
        if (l == 0)
            return pref(r);
        return pref(r) - pref(l - 1);
    }

    void upd(int i, T nw)
    {
        int now = rq(i, i);
        for (++i; i < n; i += i & -i)
        {
            t[i] -= now;
            t[i] += nw;
        }
    }

    void add(int i, T d)
    {
        for (++i; i < n; i += i & -i)
            t[i] += d;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    FenwickTree<i64> ft(n);
    for (int i = 0; i < m; ++i)
    {
        string s;
        cin >> s;
        if (s == "add")
        {
            i64 i, d;
            cin >> i >> d;
            ft.add(i - 1, d);
        }
        else
        {
            int l, r;
            cin >> l >> r;
            cout << ft.rq(l - 1, r - 1) << '\n';
        }
    }
}