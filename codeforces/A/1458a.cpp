#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int precalc = 0;
    for (int i = 1; i < n; ++i)
        precalc = abs(__gcd(precalc, a[i] - a[0]));
    for (int i = 0; i < m; ++i)
    {
        int b;
        cin >> b;
        cout << abs(__gcd(precalc, a[0] + b)) << ' ';
    }
}