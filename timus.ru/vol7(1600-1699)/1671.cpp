#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;

struct DSU
{
    int n;
    vector<int> parent;

    DSU(int k)
    {
        n = k;
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

    void unite(int i, int j)
    {
        i = get_parent(i);
        j = get_parent(j);
        if (i != j)
            parent[i] = j;
    }

    int calc_comps()
    {
        set<int> ans;
        for (int i = 0; i < n; ++i)
            ans.insert(get_parent(i));
        return ans.size();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    DSU dsu(n);

    vector<pair<int, int>> edges(m);
    for (auto &[a, b] : edges)
    {
        cin >> a >> b;
        --a;
        --b;
    }

    int q;
    cin >> q;
    vector<int> queries(q);
    for (int &i : queries)
    {
        cin >> i;
        --i;
    }

    set<int> ban(queries.begin(), queries.end());
    for (int i = 0; i < m; ++i)
    {
        if (ban.find(i) != ban.end())
            continue;
        dsu.unite(edges[i].first, edges[i].second);
    }

    vector<int> ans;
    int now_ans = dsu.calc_comps();
    for (int i = q - 1; i > -1; --i)
    {
        ans.push_back(now_ans);
        auto [f, s] = edges[queries[i]];
        if (dsu.get_parent(f) != dsu.get_parent(s))
            --now_ans;
        dsu.unite(f, s);
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans)
        cout << i << ' ';
}