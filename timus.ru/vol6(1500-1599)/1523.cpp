#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9;

struct FenwickTree
{
    vector<int> t;
    int n;

    FenwickTree(int k)
    {
        t.assign(k + 1, 0);
        n = k;
    }

    int pref(int n)
    {
        int res = 0;
        for (int i = n + 1; i > 0; i -= i & -i)
            res = (res + t[i]) % mod;
        return res;
    }

    void add(int j, int d)
    {
        for (int i = j + 1; i <= n; i += i & -i)
            t[i] = (t[i] + d) % mod;
    }

    int rq(int l, int r)
    {
        if (l == 0)
            return pref(r);
        return (pref(r) - pref(l - 1) + mod) % mod;
    }
};

int32_t main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<FenwickTree> fts(k, FenwickTree{n + 1});
    for (int i = 0; i < n; ++i)
    {
        for (int j = 1; j < k; ++j)
            fts[j].add(a[i], fts[j - 1].rq(a[i] + 1, n));

        fts[0].add(a[i], 1);
    }
    cout << fts[k - 1].rq(0, n) << '\n';
}
