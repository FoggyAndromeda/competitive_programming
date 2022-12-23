#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<bool>> mp(n + 2, vector<bool>(n + 2, true));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            char c;
            cin >> c;
            mp[i][j] = (c == '#');
        }
    }
    vector<vector<bool>> visited(n + 2, vector<bool>(n + 2, false));
    int ans = 0;
    function<void(int, int)> dfs = [&](int i, int j)
    {
        if (mp[i][j])
        {
            ++ans;
            return;
        }
        if (visited[i][j])
            return;
        visited[i][j] = true;
        dfs(i + 1, j);
        dfs(i - 1, j);
        dfs(i, j + 1);
        dfs(i, j - 1);
    };
    dfs(1, 1);
    if (!visited[n][n])
        dfs(n, n);

    ans -= 4;
    cout << 9 * ans << '\n';
}