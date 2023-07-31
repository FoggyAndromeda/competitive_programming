#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    vector<vector<int>> indexes(10);
    for (int i = 0; i < s.size(); ++i)
        indexes[s[i] - '0'].push_back(i);
    int m;
    cin >> m;
    string l, r;
    cin >> l >> r;
    int index = -1;
    bool ans = false;
    for (int i = 0; !ans && i < m; ++i)
    {
        // clog << index << '\n';
        int new_index = -1;
        for (int j = l[i] - '0'; !ans && j <= r[i] - '0'; ++j)
        {
            if (indexes[j].empty() || index >= *indexes[j].rbegin())
            {
                ans = true;
                break;
            }
            new_index = max(new_index, *upper_bound(indexes[j].begin(), indexes[j].end(), index));
        }
        index = new_index;
    }
    if (ans)
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