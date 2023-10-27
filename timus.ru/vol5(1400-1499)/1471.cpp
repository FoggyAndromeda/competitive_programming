#include <bits/stdc++.h>

using namespace std;

const int logn = 20;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b, w;
        cin >> a >> b >> w;

        edges[a].emplace_back(b, w);
        edges[b].emplace_back(a, w);
    }
    vector<int> dist(n, -1);
    vector<int> tin(n);
    vector<int> tout(n);
    dist[0] = 0;
    int timer = 0;
    vector<vector<int>> ancestor_binup(n, vector<int>(logn, -1));
    fill(ancestor_binup[0].begin(), ancestor_binup[0].end(), 0);
    function<void(int)> dfs = [&](int v)
    {
        for (int i = 1; i < logn; ++i)
            ancestor_binup[v][i] = ancestor_binup[ancestor_binup[v][i - 1]][i - 1];

        tin[v] = timer++;

        for (auto [nxt, w] : edges[v])
        {
            if (dist[nxt] > -1)
                continue;
            dist[nxt] = dist[v] + w;
            ancestor_binup[nxt][0] = v;
            dfs(nxt);
        }

        tout[v] = timer++;
    };
    dfs(0);

    function<bool(int, int)> is_ancestor = [&](int u, int v)
    {
        return tin[u] < tin[v] && tout[u] > tout[v];
    };

    function<int(int, int)> lca = [&](int u, int v)
    {
        if (u == v)
            return u;
        if (is_ancestor(u, v))
            return u;
        if (is_ancestor(v, u))
            return v;
        for (int i = logn - 1; i > -1; --i)
            if (!is_ancestor(ancestor_binup[u][i], v))
                u = ancestor_binup[u][i];
        return ancestor_binup[u][0];
    };

    int q;
    cin >> q;
    while (q-- > 0)
    {
        int f, s;
        cin >> f >> s;
        int l = lca(f, s);
        // clog << "LCA: " << l << '\n';
        cout << dist[f] + dist[s] - 2 * dist[l] << '\n';
    }
}