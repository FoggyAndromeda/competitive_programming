#include <bits/stdc++.h>

using namespace std;

struct dsu
{
    vector<int> parent;

    dsu(int n)
    {
        parent.assign(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int get_parent(int i)
    {
        if (parent[i] != i)
            return parent[i] = get_parent(parent[i]);
        return i;
    }

    bool in_same(int f, int s)
    {
        return get_parent(f) == get_parent(s);
    }

    void unite(int f, int s)
    {
        int pf = get_parent(f);
        int ps = get_parent(s);
        if (pf != ps)
            parent[pf] = ps;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < m; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edges.emplace_back(w, a, b);
    }
    dsu d(n + 1);
    sort(edges.begin(), edges.end());
    int ans = 0;
    for (auto [w, a, b] : edges)
    {
        if (d.in_same(a, b))
            continue;
        ans += w;
        d.unite(a, b);
    }
    cout << ans << '\n';
}
