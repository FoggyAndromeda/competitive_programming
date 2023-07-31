#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;

int32_t main()
{
    int n;
    cin >> n;
    vector<vector<pair<int, int>>> edges(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int f, s, w;
        cin >> f >> s >> w;
        --f;
        --s;
        edges[f].emplace_back(s, w);
        edges[s].emplace_back(f, w);
    }

    vector<int> dist(n, -1);
    stack<pair<int, int>> q;
    q.emplace(0, 0);
    while (!q.empty())
    {
        auto [v, w] = q.top();
        q.pop();
        if (dist[v] != -1)
            continue;
        dist[v] = w;
        for (auto [nxt, weight] : edges[v])
            q.emplace(nxt, w ^ weight);
    }

    int ans = 0;
    for (int i = 0; i < 61; ++i)
    {
        int cnt[2] = {0};
        for (int j = 0; j < n; ++j)
            ++cnt[(dist[j] >> i) & 1];
        int delta = (1ll << i) % mod;
        delta = (delta * cnt[0]) % mod;
        delta = (delta * cnt[1]) % mod;
        ans = (ans + delta) % mod;
    }
    cout << ans << '\n';
}