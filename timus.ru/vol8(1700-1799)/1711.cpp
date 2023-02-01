#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<string, int>> names;
    names.reserve(3 * n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
        {
            string now;
            cin >> now;
            names.push_back({now, i});
        }
    sort(names.begin(), names.end());
    int now_ind = 0;
    vector<int> ans;
    for (int i = 0; i < n; ++i)
    {
        int now;
        cin >> now;
        --now;
        while (now_ind < names.size() && names[now_ind].second != now)
            ++now_ind;
        if (now_ind < names.size())
            ans.push_back(now_ind);
    }
    if (ans.size() == n)
    {
        for (int i : ans)
            cout << names[i].first << '\n';
    }
    else
        cout << "IMPOSSIBLE\n";
}