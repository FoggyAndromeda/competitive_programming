#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<list<int>> ancestors(n);
    vector<int> count(n);
    for (int i = 0; i < m; ++i)
    {
        int x, y;
        cin >> x >> y;
        --x;
        --y;
        ++count[x];
        ++count[y];
        ancestors[x].push_back(y);
    }

    vector<int> dists(n, 0);
    function<void(int)> dfs = [&](int v)
    {
        if (dists[v] != 0)
            return;
        for (auto nxt : ancestors[v])
        {
            dfs(nxt);
            dists[v] = max(dists[v], dists[nxt] + 1);
        }
        if (dists[v] == -1)
            dists[v] = 0;
    };
    for (int i = 0; i < n; ++i)
        if (ancestors[i].size() == count[i])
            dfs(i);
    cout << *max_element(dists.begin(), dists.end()) << '\n';
}