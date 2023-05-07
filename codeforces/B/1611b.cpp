#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int a, b;
    cin >> a >> b;
    int l = 0, r = max(a, b);
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (a >= m && b >= m && (a - m) + (b - m) >= 2 * m)
            l = m;
        else
            r = m;
    }
    cout << l << '\n';
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