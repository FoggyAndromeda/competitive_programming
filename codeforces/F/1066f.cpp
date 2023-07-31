#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int INF = 0x7fff'ffff'ffff'ffff;

int dist(pair<int, int> f, pair<int, int> s)
{
    return abs(f.first - s.first) + abs(f.second - s.second);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<int, vector<pair<int, int>>> lvls;
    lvls[0].push_back({0, 0});
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        int level = max(x, y);
        lvls[level].emplace_back(x, y);
        if (lvls[level].size() == 1)
            continue;
        sort(lvls[level].begin(), lvls[level].end(),
             [](pair<int, int> f, pair<int, int> s)
             {
                 return atan2(f.first, f.second) > atan2(s.first, s.second);
             });
        if (lvls[level].size() == 2)
            continue;
        lvls[level][1] = lvls[level][2];
        lvls[level].pop_back();
    }

    int ans = 0;
    for (auto &[x, vec] : lvls)
    {
        if (vec.size() == 1)
            vec.push_back(vec[0]);
        ans += dist(vec[0], vec[1]);
    }
    vector<vector<int>> dp(lvls.size(), vector<int>(2, INF));
    dp[0][0] = 0;
    dp[0][1] = 0;
    int i = 1;
    int previous_lvl = 0;
    for (auto &[x, vec] : lvls)
    {
        if (x == 0)
            continue;
        dp[i][0] = min(dp[i - 1][0] + dist(lvls[previous_lvl][1], vec[0]),
                       dp[i - 1][1] + dist(lvls[previous_lvl][0], vec[0]));

        dp[i][1] = min(dp[i - 1][0] + dist(lvls[previous_lvl][1], vec[1]),
                       dp[i - 1][1] + dist(lvls[previous_lvl][0], vec[1]));
        previous_lvl = x;
        ++i;
    }

    cout << ans + min(dp[lvls.size() - 1][0], dp[lvls.size() - 1][1]) << '\n';
}