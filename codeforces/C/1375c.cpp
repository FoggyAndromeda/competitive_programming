#include <bits/stdc++.h>

using namespace std;

struct FenwickTree
{
    vector<int> tree;
    int n;

    FenwickTree(int k)
    {
        n = k + 1;
        tree.assign(n, 0);
    }

    void upd(int i, int d)
    {
        ++i;
        for (; i < n; i += i & -i)
            tree[i] += d;
    }

    int pref(int i)
    {
        int res = 0;
        for (++i; i > 0; i -= i & -i)
            res += tree[i];
        return res;
    }

    int rq(int l, int r)
    {
        if (l == 0)
            return pref(r);
        return pref(r) - pref(l - 1);
    }
};

void solve()
{
    int n;
    cin >> n;
    int sum = 0, prev, now;
    cin >> prev;
    for (int i = 1; i < n; ++i)
    {
        cin >> now;
        sum += now - prev;
        prev = now;
    }
    if (sum > 0)
        cout << "YES\n";
    else
        cout << "NO\n";
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