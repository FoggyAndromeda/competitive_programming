#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;

    queue<pair<int, int>> s;
    for (int i = 0; i < k; ++i)
    {
        int a;
        cin >> a;
        s.emplace(a, i);
    }
    s.emplace(1, k);

    vector<vector<int>> edges(n + 1);
    for (int i = 0; i < n - 1; ++i)
    {
        int f, s;
        cin >> f >> s;
        edges[f].push_back(s);
        edges[s].push_back(f);
    }

    vector<int> color(n + 1, -1);
    while (!s.empty())
    {
        auto [v, c] = s.front();
        s.pop();
        if (color[v] != -1)
            continue;
        color[v] = c;
        for (int nxt : edges[v])
            s.emplace(nxt, c);
    }

    bool ans = false;
    for (int i = 2; i <= n; ++i)
        ans = ans || (edges[i].size() == 1 && color[i] == k);
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}