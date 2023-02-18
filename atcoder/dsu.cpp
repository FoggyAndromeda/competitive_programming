#include <bits/stdc++.h>

using namespace std;

class dsu
{
private:
    vector<int> parent;

public:
    dsu(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; ++i)
            parent[i] = i;
    }

    int get_parent(int v)
    {
        if (parent[v] == v)
            return v;
        return parent[v] = get_parent(parent[v]);
    }

    void unite(int v, int u)
    {
        int x = get_parent(v), y = get_parent(u);
        if (x != y)
            parent[x] = y;
    }

    bool in_same(int v, int u)
    {
        return get_parent(u) == get_parent(v);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    dsu d(n);
    for (int i = 0; i < q; ++i)
    {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0)
            d.unite(u, v);
        else
            cout << d.in_same(u, v) << '\n';
    }
}