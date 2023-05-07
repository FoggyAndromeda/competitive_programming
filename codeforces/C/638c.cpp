// #pragma GCC optimize("O3,fast-math,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<list<pair<int, int>>> mp(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        mp[a].push_back({b, i});
        mp[b].push_back({a, i});
    }

    int root = 0;
    for (int i = 1; i < n; ++i)
        if (mp[i].size() > mp[root].size())
            root = i;

    vector<list<int>> ans(mp[root].size());

    list<tuple<int, int, int>> s;
    s.push_back({root, -1, -1});
    while (!s.empty())
    {
        auto [v, prev, day] = s.back();
        s.pop_back();
        int now_day = (day == 0);
        for (auto [nxt, ind] : mp[v])
        {
            if (nxt == prev)
                continue;
            ans[now_day].push_back(ind);
            s.emplace_back(nxt, v, now_day);
            ++now_day;
            if (now_day == day)
                ++now_day;
        }
    }

    cout << ans.size() << '\n';
    for (auto line : ans)
    {
        cout << line.size() << ' ';
        for (auto elem : line)
            cout << elem + 1 << ' ';
        cout << '\n';
    }
}