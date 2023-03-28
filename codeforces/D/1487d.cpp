#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 3; i < n; i += 2)
    {
        if ((i * i - 1) / 2 >= n)
            break;
        ++ans;
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