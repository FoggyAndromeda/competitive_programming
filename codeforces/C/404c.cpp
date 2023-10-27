#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> v(100'001);
    for (int i = 0; i < n; ++i)
    {
        int d;
        cin >> d;
        v[d].push_back(i);
    }
    if (v[0].size() != 1 || v[1].size() > k)
    {
        cout << "-1\n";
        exit(0);
    }
    bool possible = true;
    vector<pair<int, int>> ans;
    for (int i : v[1])
        ans.push_back({v[0][0], i});
    for (int i = 2; i < v.size(); ++i)
    {
        if (v[i].size() > (k - 1) * v[i - 1].size())
        {
            possible = false;
            break;
        }
        int ind = 0;
        for (int j : v[i - 1])
        {
            int counter = 0;
            while (counter < (k - 1) && ind < v[i].size())
            {
                ans.push_back({j, v[i][ind]});
                ++counter;
                ++ind;
            }
        }
    }
    if (!possible)
    {
        cout << "-1\n";
        return 0;
    }
    cout << ans.size() << '\n';
    for (auto [a, b] : ans)
        cout << a + 1 << ' ' << b + 1 << '\n';
}