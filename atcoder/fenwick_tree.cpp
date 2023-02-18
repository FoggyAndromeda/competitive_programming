#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

template <class T = int>
class FenwickTree
{
private:
    vector<T> t;
    int n;

    T pref(int i)
    {
        T res = 0;
        for (++i; i > 0; i -= i & -i)
            res = res + t[i];
        return res;
    }

public:
    FenwickTree(vector<T> &a)
    {
        n = a.size() + 1;
        t.assign(n, 0);
        for (int i = 0; i < n; ++i)
            upd(i, a[i]);
    }

    T rq(int l, int r)
    {
        if (l == 0)
            return pref(r);
        return pref(r) - pref(l - 1);
    }

    FenwickTree(int l)
    {
        n = l + 1;
        t.assign(n, 0);
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
    int n, q;
    cin >> n >> q;
    vector<int64_t> a(n, 0LL);
    for (auto &i : a)
        cin >> i;
    FenwickTree<int64_t> ft(a);
    while (q-- > 0)
    {
        int t, f, s;
        cin >> t >> f >> s;
        if (t == 0)
            ft.add(f, s);
        else
            cout << ft.rq(f, s - 1) << '\n';
    }
}