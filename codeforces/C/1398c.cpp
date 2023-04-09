#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve()
{
    i64 n;
    cin >> n;
    vector<i64> pref(n);
    for (i64 i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        if (i > 0)
            pref[i] = pref[i - 1] + (c - '0');
        else
            pref[i] = c - '0';
    }

    // pref[r] - pref[l] == r - l -> pref[r] - r == pref[l] - l
    // r > l && l != 0

    i64 ans = 0;
    unordered_map<i64, i64> possible_sums;
    for (i64 i = 0; i < n; ++i)
    {
        if (pref[i] == i + 1)
            ++ans;
        ans += possible_sums[pref[i] - i]++;
    }
    cout << ans << '\n';
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