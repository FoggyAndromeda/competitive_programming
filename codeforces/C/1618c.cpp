#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int gcdeven = a[0];
    for (int i = 2; i < n; i += 2)
        gcdeven = __gcd(gcdeven, a[i]);

    int gcdodd = a[1];
    for (int i = 3; i < n; i += 2)
        gcdodd = __gcd(gcdodd, a[i]);

    bool ok = true;
    for (int i = 1; i < n; i += 2)
        ok = ok && (a[i] % gcdeven != 0);
    if (ok)
    {
        cout << gcdeven << '\n';
        return;
    }

    ok = true;
    for (int i = 0; i < n; i += 2)
        ok = ok && (a[i] % gcdodd != 0);
    if (ok)
    {
        cout << gcdodd << '\n';
        return;
    }
    cout << "0\n";
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