#include <bits/stdc++.h>

using namespace std;

const vector<pair<int, int>> ds = {
    {1, 0}, {1, -1}, {1, 1}, {-1, 0}, {-1, -1}, {-1, 1}, {0, -1}, {0, 1}};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> mp(n);
    for (int i = 0; i < n; ++i)
        cin >> mp[i];

    bool ok = true;
    for (int i = 0; ok && i < n; ++i)
        for (int j = 0; ok && j < m; ++j)
            if (mp[i][j] == '*')
            {
                vector<pair<int, int>> psbl;
                for (auto [dx, dy] : ds)
                {
                    if (i + dx < 0 || i + dx >= n)
                        continue;
                    if (j + dy < 0 || j + dy >= m)
                        continue;
                    if (mp[i + dx][j + dy] == '*')
                        psbl.emplace_back(dx, dy);
                }
                if (psbl.size() != 2)
                    ok = false;
                else if (!(
                             (psbl[0].first == psbl[1].first && psbl[0].second * psbl[1].second == 0) ||
                             (psbl[0].second == psbl[1].second && psbl[0].first * psbl[1].first == 0) ||
                             abs(psbl[0].first * psbl[1].first) + abs(psbl[0].second * psbl[1].second) == 0))
                    ok = false;
            }
    if (ok)
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