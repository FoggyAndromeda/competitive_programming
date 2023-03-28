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
    vector<int> delta(n);
    for (int i = 0; i < n; ++i)
        delta[i] = ((i + a[i]) % n + n) % n;
    sort(delta.begin(), delta.end());
    bool res = 1;
    for (int i = 0; res && i < n; ++i)
        if (delta[i] != i)
            res = 0;
    if (res)
        cout << "YES\n";
    else
        cout << "NO\n";
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