#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> has_cat(n);
    for (int &i : has_cat)
        cin >> i;
    vector<list<int>> mp(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        mp[a].push_back(b);
        mp[b].push_back(a);
    }
    int ans = 0;
    function<void(int, int, int)> dfs = [&](int v, int prev, int countcat)
    {
        if (countcat > m)
            return;
        if (v != 0 && mp[v].size() == 1 && countcat + has_cat[v] <= m)
        {
            ++ans;
            return;
        }
        if (has_cat[v])
            for (int nxt : mp[v])
            {
                if (nxt == prev)
                    continue;
                dfs(nxt, v, countcat + 1);
            }
        else
            for (int nxt : mp[v])
            {
                if (nxt == prev)
                    continue;
                dfs(nxt, v, 0);
            }
    };
    dfs(0, -1, 0);
    cout << ans << '\n';
}