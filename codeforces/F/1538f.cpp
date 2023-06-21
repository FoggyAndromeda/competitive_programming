#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int l, r;
    cin >> l >> r;
    int ans = 0;
    while (l > 0 || r > 0)
    {
        ans += r - l;
        r /= 10;
        l /= 10;
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