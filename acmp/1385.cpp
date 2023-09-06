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

    int get_parent(int n)
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
        parent[pf] = parent[ps];
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    dsu d(n + 1);
    vector<pair<int, int>> ans;
    for (int i = 0; i < m; ++i)
    {
        int f, s;
        cin >> f >> s;
        if (d.in_same(f, s))
            continue;
        ans.emplace_back(f, s);
        d.unite(f, s);
    }
    for (auto [f, s] : ans)
        cout << f << ' ' << s << '\n';
}