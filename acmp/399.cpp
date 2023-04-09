#include <bits/stdc++.h>

using namespace std;

const int INF = 0x7fffffff;

// int cnt = 0;

// void *operator new(size_t size)
// {
//     ++cnt;
//     return malloc(size);
// }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    string asdfasdf;
    getline(cin, asdfasdf);
    for (int i = 0; i < n; ++i)
        getline(cin, mp[i]);
    // clog << "INPUT ENDED\n";

    vector<vector<int>> visits(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            visits[i][j] = INF * (mp[i][j] == '@');

    bool is_ok = false;
    stack<pair<int, int>> s;
    s.push({1, 1});
    while (!s.empty())
    {
        auto [x, y] = s.top();
        s.pop();
        if (visits[x][y] > 0)
            continue;
        if (x == n - 2 && y == m - 2)
            is_ok = true;
        visits[x][y] = 1;
        s.push({x + 1, y});
        s.push({x - 1, y});
        s.push({x, y + 1});
        s.push({x, y - 1});
    }

    if (!is_ok)
    {
        cout << "-1\n";
        return 0;
    }

    int x = 1,
        y = 1;
    // directions:
    // 0 - down
    // 1 - right
    // 2 - up
    // 3 - left
    vector<pair<int, int>> deltas = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int now_dir = -1;
    int ans = 0;
    int max_moves = 1e7;
    vector<int> valid_dir;
    while (x != n - 2 || y != m - 2)
    {
        // clog << "NOW IN " << x << ' ' << y << " MOVE " << now_dir << '\n';
        int min_visits = INF;
        valid_dir.clear();
        for (int i = 0; i < 4; ++i)
        {
            auto [dx, dy] = deltas[i];
            if (visits[x + dx][y + dy] == min_visits)
                valid_dir.push_back(i);
            if (visits[x + dx][y + dy] < min_visits)
            {
                min_visits = visits[x + dx][y + dy];
                valid_dir.clear();
                valid_dir.push_back(i);
            }
        }
        if (find(valid_dir.begin(), valid_dir.end(), now_dir) == valid_dir.end())
            now_dir = *valid_dir.begin();
        ++visits[x][y];
        x += deltas[now_dir].first;
        y += deltas[now_dir].second;
        ++ans;
    }
    cout << ans << '\n';
    // clog << cnt;
}