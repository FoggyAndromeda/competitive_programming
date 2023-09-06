#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> edges[n + 1];
    for (int i = 0; i < n - 1; ++i)
    {
        int f, s;
        cin >> f >> s;
        edges[f].push_back(s);
        edges[s].push_back(f);
    }

    vector<int> sizes(n + 1, 0);

    vector<char> result(n + 1, '!');
    function<int(int, int)> dfs = [&](int v, int prev)
    {
        if (result[v] != '!')
            return sizes[v] = 0;
        sizes[v] = 1;
        for (int nxt : edges[v])
            if (nxt != prev)
                sizes[v] += dfs(nxt, v);
        return sizes[v];
    };

    function<int(int)> find_centroid = [&](int v)
    {
        dfs(v, -1);
        int now_sz = sizes[v];
        while (1)
        {
            int w = -1;
            for (int nxt : edges[v])
            {
                if (result[nxt] != '!')
                    continue;
                if (sizes[nxt] > sizes[v])
                    continue;
                if (2 * sizes[nxt] >= now_sz)
                {
                    w = nxt;
                    break;
                }
            }
            if (w == -1)
                break;
            v = w;
        }
        return v;
    };

    stack<pair<int, char>> s;
    s.push({1, 'A'});

    while (!s.empty())
    {
        auto [v, c] = s.top();
        s.pop();
        // clog << v << ' ' << c << '\n';
        int center = find_centroid(v);
        result[center] = c;
        for (auto nxt : edges[center])
            if (result[nxt] == '!')
                s.push({nxt, c + 1});
    }
    for (int i = 1; i < n + 1; ++i)
        cout << result[i] << ' ';
    cout << '\n';
}