#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> walls(n + 2, vector<bool>(m + 2, false));
    for (int i = 0; i < m + 2; ++i)
        walls[0][i] = walls[n + 1][i] = true;
    for (int i = 0; i < n + 2; ++i)
        walls[i][0] = walls[i][m + 1] = true;

    vector<pair<int, int>> good;
    for (int i = 1; i <= n; ++i)
    {
        string s;
        cin >> s;
        for (int j = 1; j <= m; ++j)
        {
            if (s[j - 1] == 'G')
                good.emplace_back(i, j);
            if (s[j - 1] == '#')
                walls[i][j] = true;
            if (s[j - 1] == 'B')
                walls[i][j] = walls[i + 1][j] = walls[i - 1][j] = walls[i][j + 1] = walls[i][j - 1] = true;
        }
    }

    vector<vector<bool>> visited(n + 2, vector<bool>(m + 2, false));
    stack<pair<int, int>> s;
    s.emplace(n, m);
    while (!s.empty())
    {
        auto [x, y] = s.top();
        s.pop();
        if (visited[x][y] || walls[x][y])
            continue;
        visited[x][y] = true;
        s.emplace(x + 1, y);
        s.emplace(x - 1, y);
        s.emplace(x, y + 1);
        s.emplace(x, y - 1);
    };

    bool ans = true;
    for (auto [x, y] : good)
        ans = ans && visited[x][y];
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