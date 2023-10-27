#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> colors(n);
    for (int i = 0; i < n; ++i)
        cin >> colors[i];
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
    vector<int> ans(n, -1);
    vector<int> max_count(n, -1);
    function<void(int, int, map<int, int> &)> dfs = [&](int v, int prev, map<int, int> &mp)
    {
        ++mp[colors[v]];
        max_count[v] = 1;
        ans[v] = colors[v];
        for (int nxt : edges[v])
        {
            if (nxt == prev)
                continue;
            map<int, int> nxt_mp;
            dfs(nxt, v, nxt_mp);
            if (nxt_mp.size() > mp.size())
            {
                swap(mp, nxt_mp);
                max_count[v] = max_count[nxt];
                ans[v] = ans[nxt];
            }
            for (auto [col, cnt] : nxt_mp)
            {
                mp[col] += cnt;
                if (max_count[v] == mp[col])
                    ans[v] += col;
                if (max_count[v] < mp[col])
                {
                    ans[v] = col;
                    max_count[v] = mp[col];
                }
            }
        }
    };
    map<int, int> mp;
    dfs(0, -1, mp);
    for (auto elem : ans)
        cout << elem << ' ';
    cout << '\n';
}