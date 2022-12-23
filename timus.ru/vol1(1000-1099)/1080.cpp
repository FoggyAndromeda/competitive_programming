#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mp(n);
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        --k;
        while (k != -1)
        {
            mp[k].push_back(i);
            mp[i].push_back(k);
            cin >> k;
            --k;
        }
    }
    vector<int> color(n, -1);
    bool possible = true;
    function<void(int, int)> dfs = [&](int v, int col)
    {
        if (color[v] != -1)
        {
            possible = possible && (color[v] == col);
            return;
        }
        color[v] = col;
        for (int nxt : mp[v])
            dfs(nxt, (col + 1) % 2);
    };
    for (int i = 0; i < n; ++i)
    {
        if (color[i] == -1)
            dfs(i, 0);
    }
    if (possible)
    {
        for (int i : color)
            cout << i;
        cout << '\n';
    }
    else
    {
        cout << "-1\n";
    }
}