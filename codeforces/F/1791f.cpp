#include <bits/stdc++.h>

using namespace std;

template <class T>
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
        for (int i = 0; i < a.size(); ++i)
            upd(i, a[i]);
    }

    FenwickTree(int l)
    {
        n = l + 1;
        t.assign(n, 0);
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

    T lowerbound(T v)
    {
        T sum = 0;
        int pos = 0, lgn = __lg(n);
        for (int i = lgn; i >= 0; --i)
        {
            if (pos + (1 << i) < n - 1 && sum + t[pos + (1 << i)] < v)
            {
                sum += t[pos + (1 << i)];
                pos += (1 << i);
            }
        }
        return pos;
    }

    T operator()(int l, int r)
    {
        return rq(l, r);
    }

    T operator()(int r)
    {
        return pref(r);
    }

    T operator[](int i)
    {
        return rq(i, i);
    }
};

int calcsum(int a)
{
    int res = 0;
    while (a > 0)
    {
        res += a % 10;
        a /= 10;
    }
    return res;
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<tuple<int, int, int>> points;
    points.reserve(2 * q);

    for (int i = 0; i < q; ++i)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            points.push_back({l, 0, i});
            points.push_back({r, 2, i});
        }
        else
        {
            int r;
            cin >> r;
            --r;
            points.push_back({r, 1, i});
        }
    }
    sort(points.begin(), points.end());
    vector<int> results(q, -1);
    FenwickTree<int> ft(q);

    for (auto [x, type, queryind] : points)
    {
        if (type == 0)
            ft.add(queryind, 1);
        if (type == 2)
            ft.add(queryind, -1);
        if (type == 1)
        {
            int num_opened = ft.rq(0, queryind);
            x = a[x];
            for (int j = 0; x > 9 && j < num_opened; ++j)
                x = calcsum(x);
            results[queryind] = x;
        }
    }
    for (auto res : results)
        if (res > 0)
            cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}