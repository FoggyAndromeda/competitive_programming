#include <bits/stdc++.h>

using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t

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

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n), all_numbers(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        all_numbers[i] = a[i];
    }

    sort(all_numbers.begin(), all_numbers.end());
    for (int i = 0; i < n; ++i)
        a[i] = lower_bound(all_numbers.begin(), all_numbers.end(), a[i]) - all_numbers.begin();

    FenwickTree<int> ft(1'000'000);
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int more = ft.rq(a[i], n - 1);
        int less = a[i] - ft.rq(0, a[i]);
        // clog << less << ' ' << more << '\n';
        ans += less * more;
        ft.add(a[i], 1);
    }
    cout << ans << '\n';

    // ordered_set<int> visited_numbers;
    // int ans = 0;
    // for (int i = 0; i < n; ++i)
    // {
    //     int less = i - visited_numbers.order_of_key(a[i]);
    //     int more = all_numbers.order_of_key(a[i]) - visited_numbers.order_of_key(a[i]);
    //     ans += less * more;
    //     visited_numbers.insert(a[i]);
    // }
    // cout << ans << '\n';
}