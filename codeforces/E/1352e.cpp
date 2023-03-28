#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    vector<int> prefs(n);
    prefs[0] = a[0];
    for (int i = 1; i < n; ++i)
        prefs[i] = prefs[i - 1] + a[i];
    vector<int> count(8001, 0);
    for (int i = 0; i < n; ++i)
    {
        if (i > 0 && prefs[i] < 8001)
            count[prefs[i]] = 1;
        for (int j = 0; j < i - 1; ++j)
            if (prefs[i] - prefs[j] < 8001)
                count[prefs[i] - prefs[j]] = 1;
    }
    int ans = 0;
    for (int i : a)
        ans += count[i];
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