#include <bits/stdc++.h>

using namespace std;

const int INF = 0x7ffffff;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    queue<tuple<int, int, int>> s;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            int now;
            cin >> now;
            if (now == 1)
                s.push({i, j, 0});
        }
    vector<vector<int>> ans(n, vector<int>(m, INF));
    while (!s.empty())
    {
        auto [x, y, d] = s.front();
        s.pop();
        // clog << '\t' << x << ' ' << y << ' ' << d << '\n';
        if (x < 0 || x >= n)
            continue;
        if (y < 0 || y >= m)
            continue;
        if (ans[x][y] <= d)
            continue;
        ans[x][y] = d;
        s.push({x + 1, y, d + 1});
        s.push({x - 1, y, d + 1});
        s.push({x, y + 1, d + 1});
        s.push({x, y - 1, d + 1});
    }
    for (auto &line : ans)
    {
        for (auto elem : line)
            cout << elem << ' ';
        cout << '\n';
    }
}