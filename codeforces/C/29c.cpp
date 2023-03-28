#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, vector<int>> mp;
    unordered_set<int> one_time;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        mp[a].push_back(b);
        mp[b].push_back(a);
        if (mp[a].size() == 1)
            one_time.insert(a);
        if (mp[b].size() == 1)
            one_time.insert(b);
        if (mp[a].size() == 2)
            one_time.erase(one_time.find(a));
        if (mp[b].size() == 2)
            one_time.erase(one_time.find(b));
    }
    int a = *one_time.begin();
    vector<int> ans(n + 1);
    for (int i = 0; i <= n; ++i)
    {
        ans[i] = a;
        if (i == 0)
            a = mp[a][0];
        else
            a = (mp[a][0] == ans[i - 1] ? mp[a][1] : mp[a][0]);
    }
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}