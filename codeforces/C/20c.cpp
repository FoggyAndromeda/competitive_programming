#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int inf = 0x7fffffff'ffffffff;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < m; ++i)
    {
        int f, s, w;
        cin >> f >> s >> w;
        --f;
        --s;
        edges[f].emplace_back(s, w);
        edges[s].emplace_back(f, w);
    }
    vector<int> dist(n, inf);
    dist[0] = 0;
    vector<int> parent(n, -1);
    priority_queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int v = q.top();
        q.pop();
        for (auto [nxt, w] : edges[v])
        {
            if (dist[nxt] <= dist[v] + w)
                continue;
            dist[nxt] = dist[v] + w;
            parent[nxt] = v;
            q.push(nxt);
        }
    }
    // for (auto i : dist)
    //     clog << i << ' ';
    if (parent[n - 1] == -1)
    {
        cout << "-1\n";
        return 0;
    }
    vector<int> ans;
    int now = n - 1;
    while (now != -1)
    {
        ans.push_back(now);
        now = parent[now];
    }
    reverse(ans.begin(), ans.end());
    for (int i : ans)
        cout << i + 1 << ' ';
    cout << '\n';
}