#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> colors(n);
    int cntb = 0, cntr = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> colors[i];
        cntb += colors[i] == 2;
        cntr += colors[i] == 1;
    }
    vector<vector<int>> edges(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int f, s;
        cin >> f >> s;
        --f;
        --s;
        edges[f].push_back(s);
        edges[s].push_back(f);
    }
    int ans = 0;

    function<pair<int, int>(int, int)> dfs = [&](int v, int prev)
    {
        // clog << v << '\n';
        int blue = colors[v] == 2;
        int red = colors[v] == 1;
        for (int nxt : edges[v])
        {
            if (nxt == prev)
                continue;
            auto [db, dr] = dfs(nxt, v);
            blue += db;
            red += dr;
        }
        if (blue == cntb && red == 0)
            ++ans;
        if (red == cntr && blue == 0)
            ++ans;
        return pair<int, int>{blue, red};
    };
    dfs(0, -1);
    cout << ans << '\n';
}