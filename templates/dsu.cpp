#include <bits/stdc++.h>

using namespace std;

// !UNCHECKED

struct DSU
{
    int n;
    vector<int> parent;

    DSU(int k)
    {
        n = k + 1;
        parent.assign(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find_parent(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_parent(parent[v]);
    }

    void unite(int v, int u)
    {
        int x = find_parent(v), y = find_parent(u);
        if (x != y)
        {
            parent[x] = y;
        }
    }
};

int main()
{
}