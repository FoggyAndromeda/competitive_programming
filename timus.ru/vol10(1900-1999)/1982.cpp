#pragma GCC optimize("Ofast")

#include <bits/stdc++.h>

using namespace std;

struct DSU
{
    int n;
    vector<int> parent;

    DSU(int n_ = 0)
    {
        n = n_;
        parent.assign(n, 0);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int get_parent(int i)
    {
        if (parent[i] == i)
            return i;
        return parent[i] = get_parent(parent[i]);
    }

    bool in_same(int i, int j)
    {
        return get_parent(i) == get_parent(j);
    }

    void unite(int i, int j)
    {
        i = get_parent(i);
        j = get_parent(j);
        if (i != j)
            parent[i] = j;
    }
};

int main()
{
    int n, k;
    cin >> n >> k;
    DSU dsu(n);

    vector<int> stations(k);
    for (int &i : stations)
        cin >> i;
    for (int &i : stations)
        --i;
    for (int i = 1; i < k; ++i)
        dsu.unite(stations[0], stations[i]);

    vector<vector<int>> mp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> mp[i][j];

    vector<tuple<int, int, int>> edges;
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            edges.push_back({mp[i][j], i, j});

    sort(edges.begin(), edges.end());

    int ans = 0;
    for (auto [w, i, j] : edges)
    {
        if (dsu.in_same(i, j))
            continue;
        ans += w;
        dsu.unite(i, j);
    }
    cout << ans << '\n';
}