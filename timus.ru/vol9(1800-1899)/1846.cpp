#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;

int mygcd(int a, int b)
{
    if (a == -1)
        return b;
    if (b == -1)
        return a;
    return gcd(a, b);
}

const int maxn = 1e5 + 1;

struct segtree
{
    vector<int> t;
    int n;

    segtree()
    {
        n = maxn;
        t.assign(4 * n, -1);
    }

    int rq(int lr, int rr, int v, int l, int r)
    {
        if (lr == l && rr == r)
            return t[v];
        int m = (l + r) >> 1;
        if (rr <= m)
            return rq(lr, rr, 2 * v, l, m);
        if (m + 1 <= lr)
            return rq(lr, rr, 2 * v + 1, m + 1, r);
        return mygcd(rq(lr, m, 2 * v, l, m), rq(m + 1, rr, 2 * v + 1, m + 1, r));
    }

    void upd(int i, int k, int v, int l, int r)
    {
        if (l == r && i == l)
        {
            t[v] = k;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m)
            upd(i, k, 2 * v, l, m);
        else
            upd(i, k, 2 * v + 1, m + 1, r);
        t[v] = mygcd(t[2 * v], t[2 * v + 1]);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<int, list<int>> indexes;
    segtree st;
    int now_ind = 0;

    int n;
    cin >> n;
    while (n-- > 0)
    {
        char c;
        int x;
        cin >> c >> x;
        if (c == '+')
        {
            st.upd(now_ind, x, 1, 0, maxn - 1);
            indexes[x].push_back(now_ind);
            ++now_ind;
        }
        else
        {
            st.upd(*indexes[x].rbegin(), -1, 1, 0, maxn - 1);
            indexes[x].pop_back();
        }
        cout << abs(st.rq(0, maxn - 1, 1, 0, maxn - 1)) << '\n'; // gcd(empty set) == 1, but rq(e. s.) -> -1 so abs(rq) for 1
    }
}