#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve()
{
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> x[i] >> y[i];
    }
    sort(x.begin(), x.end());
    sort(y.begin(), y.end());
    if (n % 2 == 1)
        cout << "1\n";
    else
        cout << (x[n / 2] - x[(n - 1) / 2] + 1) * (y[n / 2] - y[(n - 1) / 2] + 1) << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}