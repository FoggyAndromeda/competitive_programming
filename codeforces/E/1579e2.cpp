#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using i64 = int64_t;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename T>
using ordered_multiset = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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

void solve()
{
    i64 n;
    cin >> n;
    vector<i64> a(n);
    ordered_set<i64> compress;
    for (i64 &i : a)
    {
        cin >> i;
        compress.insert(i);
    }
    for (i64 &i : a)
        i = compress.order_of_key(i);
    i64 csize = compress.size();
    FenwickTree<i64> ft(csize);
    i64 ans = 0;
    for (i64 &i : a)
    {
        if (i < csize - 1 && i > 0)
            ans += min(ft.rq(i + 1, csize - 1), ft.rq(0, i - 1));
        ft.add(i, 1);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        solve();
    }
}