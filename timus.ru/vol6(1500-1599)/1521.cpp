#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

template <class T = i64>
class FenwickTree
{
private:
    vector<T> t;
    i64 n;

    T pref(i64 i)
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
        for (i64 i = 0; i < n - 1; ++i)
            upd(i, a[i]);
    }

    FenwickTree(i64 l)
    {
        n = l + 1;
        t.assign(n, 0);
    }

    T rq(i64 l, i64 r)
    {
        if (r >= n - 1)
            return pref(r % (n - 1)) + rq(l, n - 2) + pref(n - 2) * (r / (n - 1) - 1);
        if (l == 0)
            return pref(r);
        return pref(r) - pref(l - 1);
    }

    void upd(i64 i, T nw)
    {
        i64 now = rq(i, i);
        for (++i; i < n; i += i & -i)
        {
            t[i] -= now;
            t[i] += nw;
        }
    }

    void add(i64 i, T d)
    {
        for (++i; i < n; i += i & -i)
            t[i] += d;
    }
};

int main()
{
    int n, p;
    cin >> n >> p;
    vector<i64> a(n, 1);
    FenwickTree<i64> ft(a);
    int now = 0;
    for (int i = 0; i < n; ++i)
    {
        i64 l = now + p - 2, r = now + 10'000'000'000ll;
        while (r - l > 1)
        {
            i64 m = (l + r) >> 1;
            if (ft.rq(now, m) < p)
                l = m;
            else
                r = m;
        }
        now = r % n;
        ft.add(now, -1);
        cout << now + 1 << ' ';
    }
}