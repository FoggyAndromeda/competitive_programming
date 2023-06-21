#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> edges(n);
    for (int i = 0; i < m; ++i)
    {
        int f, s;
        cin >> f >> s;
        --f;
        --s;
        edges[f].push_back(s);
        edges[s].push_back(f);
    }
    vector<int> components(n, -1);
    int comp = 1;
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (components[i] != -1)
            continue;

        bool ok = true;
        stack<pair<int, int>> s;
        s.emplace(i, -1);

        while (!s.empty())
        {
            auto [v, prev] = s.top();
            s.pop();
            if (components[v] != -1)
                continue;
            components[v] = comp;
            ok = ok && (edges[v].size() == 2);
            for (auto nxt : edges[v])
                if (nxt != prev)
                    s.emplace(nxt, v);
        }

        ans += ok;
        ++comp;
    }
    cout << ans << '\n';
}