#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    vector<vector<int>> roads(n);
    for (int i = 0; i < n - 1; ++i)
    {
        int f, s;
        cin >> f >> s;
        --f;
        --s;
        roads[f].push_back(s);
        roads[s].push_back(f);
    }

    vector<int> vert(n);
    function<int(int, int, int)> dfs = [&](int v, int d, int prev)
    {
        int vert_counter = 0;
        for (int nxt : roads[v])
        {
            if (nxt == prev)
                continue;
            vert_counter += dfs(nxt, d + 1, v);
        }
        vert[v] = d - vert_counter;
        return vert_counter + 1;
    };
    dfs(0, 0, -1);

    // for (auto elem : vert)
    //     clog << elem << ' ';
    // clog << '\n';

    sort(vert.begin(), vert.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < k; ++i)
        ans += vert[i];
    cout << ans << '\n';
}