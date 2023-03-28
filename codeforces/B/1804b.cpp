#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k, d, w;
    cin >> n >> k >> d >> w;
    vector<int> t(n);
    for (int i = 0; i < n; ++i)
        cin >> t[i];
    int ans = 0, left = 0, lastpack = 0;
    for (int i = 0; i < n; ++i)
    {
        if (left == 0 || t[i] - lastpack > d)
        {
            ++ans;
            left = k;
            lastpack = t[i] + w;
        }
        --left;
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