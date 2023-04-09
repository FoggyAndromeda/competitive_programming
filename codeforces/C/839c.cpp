#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<list<int>> mp(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int f, s;
        cin >> f >> s;
        --f;
        --s;
        mp[f].push_back(s);
        mp[s].push_back(f);
    }

    function<double(int, int)> dfs = [&](int v, int prev)
    {
        double res = 0;
        for (int nxt : mp[v])
            if (nxt != prev)
                res += dfs(nxt, v) + 1;
        if (res == 0)
            return double(0);
        return double(res) / double(mp[v].size() - (prev != -1));
    };

    cout << fixed << setprecision(9) << dfs(0, -1) << '\n';
}