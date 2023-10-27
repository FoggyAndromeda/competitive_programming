// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

constexpr int bufsize = 200;
constexpr int maxlog = 20;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }

    vector<int> tin(n, -1);
    vector<int> tout(n, -1);
    vector<int> dist(n, -1);

    vector<vector<int>> parents(n, vector<int>(maxlog, 0));

    int timer = 0;
    function<void(int, int)> dfs1 = [&](int v, int p)
    {
        tin[v] = timer++;
        for (int nxt : edges[v])
        {
            if (nxt == p)
                continue;
            dist[nxt] = dist[v] + 1;
            parents[nxt][0] = v;
            dfs1(nxt, v);
        }
        tout[v] = timer++;
    };
    dist[0] = 0;
    dfs1(0, -1);

    for (int i = 1; i < maxlog; ++i)
        for (int j = 0; j < n; ++j)
            parents[j][i] = parents[parents[j][i - 1]][i - 1];

    function<bool(int, int)> is_parent = [&](int a, int b)
    {
        return tin[a] < tin[b] && tout[a] > tout[b];
    };

    function<int(int, int)> find_lca = [&](int a, int b)
    {
        if (is_parent(a, b))
            return a;
        if (is_parent(b, a))
            return b;
        for (int i = maxlog - 1; i > -1; --i)
            if (!is_parent(parents[a][i], b))
                a = parents[a][i];
        return parents[a][0];
    };

    function<int(int, int)> find_dist = [&](int a, int b)
    {
        if (a == b)
            return 0;
        int lca = find_lca(a, b);
        // clog << "\tlca between " << a << " and " << b << " is " << lca << '\n';
        return dist[a] + dist[b] - 2 * dist[lca];
    };

    deque<pair<int, int>> red;

    vector<int> answer(dist);

    for (int i = 0; i < m; ++i)
    {
        int type, v;
        cin >> type >> v;
        --v;
        if (type == 1)
        {
            // clog << "updated " << v << '\n';
            red.push_back({v, 0});
            if (red.size() == bufsize)
            {
                while (!red.empty())
                {
                    auto [v, d] = red.front();
                    red.pop_front();
                    if (answer[v] <= d)
                        continue;
                    answer[v] = d;
                    for (auto nxt : edges[v])
                        red.emplace_back(nxt, d + 1);
                }
            }
            continue;
        }
        int result = answer[v];
        for (auto [r, d] : red)
            result = min(result, find_dist(v, r));
        cout << result << '\n';
    }
}
