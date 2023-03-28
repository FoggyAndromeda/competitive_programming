#include <bits/stdc++.h>

using namespace std;
const int INF = 0x7fffffff;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    vector<vector<char>> mp(n, vector<char>(m));
    int x, y;
    int countdots = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
        {
            cin >> mp[i][j];
            if (mp[i][j] == '.')
            {
                x = i;
                y = j;
                ++countdots;
                mp[i][j] = 'X';
            }
        }
    stack<pair<int, int>> s;
    s.push({x, y});
    while (!s.empty() && countdots > k)
    {
        auto [i, j] = s.top();
        s.pop();
        if (i < 0 || i >= n)
            continue;
        if (j < 0 || j >= m)
            continue;
        if (mp[i][j] != 'X')
            continue;
        mp[i][j] = '.';
        --countdots;
        s.push({i + 1, j});
        s.push({i - 1, j});
        s.push({i, j + 1});
        s.push({i, j - 1});
    }
    for (auto &line : mp)
    {
        for (auto elem : line)
            cout << elem;
        cout << '\n';
    }
}