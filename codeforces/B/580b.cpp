#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 n, d;
    cin >> n >> d;
    vector<pair<i64, i64>> f(n);
    for (i64 i = 0; i < n; ++i)
        cin >> f[i].first >> f[i].second;
    sort(f.begin(), f.end());
    i64 l = 0, r = 1;
    i64 nows = f[0].second;
    i64 ans = nows;
    while (l < n && r < n)
    {
        while (r < n && f[r].first - f[l].first < d)
        {
            nows += f[r].second;
            ++r;
        }
        clog << l << ' ' << r << ' ' << nows << '\n';
        ans = max(ans, nows);
        nows -= f[l].second;
        ++l;
    }
    cout << ans << '\n';
}