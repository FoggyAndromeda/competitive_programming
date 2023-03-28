#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve()
{
    i64 n;
    cin >> n;
    vector<i64> a(n);
    for (i64 i = 0; i < n; ++i)
        cin >> a[i];
    i64 ans = 0;
    for (i64 i = 1; i < n; ++i)
    {
        if (a[i] < a[i - 1])
        {
            ans = max(ans, __lg(a[i - 1] - a[i]) + 1);
            a[i] = a[i - 1];
        }
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