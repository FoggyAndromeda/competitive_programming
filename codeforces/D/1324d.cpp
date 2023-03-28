#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using i64 = int64_t;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

/*
ai + aj > bi + bj
ai - bi > bj - aj
*/

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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<i64> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<i64> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i];

    // compress coordinates
    ordered_set<i64> compress;
    for (int i = 0; i < n; ++i)
    {
        b[i] -= a[i];
        compress.insert(b[i]);
        compress.insert(-b[i]);
    }
    // -b[i] > b[j], i < j

    // for (auto elem : b)
    //     clog << elem << ' ';
    // clog << '\n';

    const int len = 4e5;
    FenwickTree<i64> count(len);
    i64 ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ans += count.rq(compress.order_of_key(b[i]) + 1, len - 1);
        count.add(compress.order_of_key(-b[i]), 1);
    }

    cout << ans << '\n';
}