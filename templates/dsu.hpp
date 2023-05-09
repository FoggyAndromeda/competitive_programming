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