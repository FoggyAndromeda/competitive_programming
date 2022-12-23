#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> children(n);
    for (int i = 0; i < n; ++i)
    {
        int now;
        cin >> now;
        while (now != 0)
        {
            --now;
            children[i].push_back(now);
            cin >> now;
        }
    }
    vector<bool> visited(n);
    vector<int> ans;
    function<void(int)> dfs = [&](int v)
    {
        visited[v] = true;
        for (int nxt : children[v])
        {
            if (!visited[nxt])
                dfs(nxt);
        }
        ans.push_back(v);
    };
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
            dfs(i);
    }
    reverse(ans.begin(), ans.end());
    for (int a : ans)
        cout << a + 1 << ' ';
    cout << '\n';
}