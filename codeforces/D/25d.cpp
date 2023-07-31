#include <bits/stdc++.h>

using namespace std;

class DSU
{
private:
    int n;
    vector<int> parent;

public:
    DSU(int k)
    {
        n = k + 1;
        parent.assign(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int get_parent(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = get_parent(parent[v]);
    }

    void unite(int v, int u)
    {
        int x = get_parent(v), y = get_parent(u);
        if (x != y)
        {
            parent[x] = y;
        }
    }

    bool in_same(int v, int u)
    {
        return get_parent(v) == get_parent(u);
    }

    int count_comp()
    {
        set<int> ans;
        for (int i = 0; i < n; ++i)
            ans.insert(get_parent(i));
        return ans.size();
    }
};

int main()
{
    int n;
    cin >> n;
    DSU dsu(n);
    vector<pair<int, int>> to_delete;
    for (int i = 0; i < n - 1; ++i)
    {
        int f, s;
        cin >> f >> s;
        --f;
        --s;
        if (dsu.in_same(f, s))
            to_delete.emplace_back(f, s);
        dsu.unite(f, s);
    }
    vector<tuple<int, int, int, int>> ans;
    for (auto [f, s] : to_delete)
    {
        for (int i = 0; i < n; ++i)
        {
            if (!dsu.in_same(i, f))
            {
                dsu.unite(f, i);
                ans.emplace_back(f + 1, s + 1, f + 1, i + 1);
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto [a, b, c, d] : ans)
        cout << a << ' ' << b << ' ' << c << ' ' << d << '\n';
}