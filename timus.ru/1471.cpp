#include <bits/stdc++.h>

using namespace std;

template <class T = int>
class segtree
{
    vector<T> t;
    int n;
    function<T(T, T)> f = [](T a, T b)
    {
        return min(a, b);
    };

    void build(int v, int l, int r, vector<T> &a)
    {
        if (l == r)
        {
            t[v] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(2 * v, l, m, a);
        build(2 * v + 1, m + 1, r, a);
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }

public:
    segtree(vector<T> a)
    {
        n = a.size();
        t.assign(4 * n, 0);
        build(1, 0, n - 1, a);
    }

    segtree(int k = 100'001)
    {
        n = k;
        t.assign(4 * n, 0);
    }

    void add(int i, int d, int v = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l == r)
        {
            t[v] += d;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m)
            add(i, d, 2 * v, l, m);
        else
            add(i, d, 2 * v + 1, m + 1, r);
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }

    void upd(int i, int a, int v = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l > r)
            return;
        if (l == r && l == i)
        {
            t[v] = a;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m)
            upd(i, a, 2 * v, l, m);
        else
            upd(i, a, 2 * v + 1, m + 1, r);
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }

    T rq(int ql, int qr, int v = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (ql > qr)
            return 0;
        if (ql == l && qr == r)
            return t[v];
        int m = (l + r) >> 1;

        if (qr <= m)
            return rq(ql, qr, 2 * v, l, m);
        if (m + 1 <= ql)
            return rq(ql, qr, 2 * v + 1, m + 1, r);

        return f(rq(ql, m, 2 * v, l, m), rq(m + 1, qr, 2 * v + 1, m + 1, r));
    }
};

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);

    int n;
    cin >> n;
    vector<list<pair<int, int>>> mp(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        mp[a].push_back({b, w});
        mp[b].push_back({a, w});
    }

    vector<int> weight(n, 0), depth, vtx, ind(n);

    function<void(int, int, int)> dfs = [&](int now, int prev, int d)
    {
        depth.push_back(d);
        vtx.push_back(now);
        ind[now] = vtx.size() - 1;

        for (auto [nxt, w] : mp[now])
        {
            if (nxt == prev)
                continue;
            weight[nxt] = weight[now] + w;
            dfs(nxt, now, d + 1);

            depth.push_back(d);
            vtx.push_back(now);
        }
    };
    dfs(0, -1, 0);

    // for (auto elem : depth)
    //     clog << elem << ' ';
    // clog << '\n';

    // for (auto elem : vtx)
    //     clog << elem << ' ';
    // clog << '\n';

    // for (auto v : ind)
    //     clog << v << ' ';
    // clog << '\n';

    segtree<int> st(depth);
    int m;
    cin >> m;
    while (m-- > 0)
    {
        int l, r;
        cin >> l >> r;
        int lca = vtx[st.rq(ind[l], ind[r])];
        clog << weight[l] << ' ' << weight[r] << ' ' << lca << ' ' << st.rq(ind[l], ind[r]) << '\n';
        cout << weight[l] + weight[r] - 2 * weight[lca] << '\n';
        // из ДО надо возвращать ИНДЕКС, а не минимум!
    }
}