#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> friends(n);
    for (int i = 0; i < n; ++i)
    {
        int f;
        cin >> f;
        while (f > 0)
        {
            friends[i].push_back(f - 1);
            cin >> f;
        }
    }
    vector<int> teams(n, -1);
    function<void(int, int)> dfs = [&](int v, int team)
    {
        teams[v] = team;
        for (auto nxt : friends[v])
        {
            if (teams[nxt] == -1)
            {
                dfs(nxt, (team + 1) % 2);
            }
        }
    };
    for (int i = 0; i < n; ++i)
        if (teams[i] == -1)
            dfs(i, 0);
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        if (teams[i] == 0)
            ans.push_back(i + 1);
    }
    cout << ans.size() << '\n';
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}