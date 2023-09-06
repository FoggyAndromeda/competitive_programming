#include <bits/stdc++.h>

using namespace std;

const int mod = 998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    set<int> primes;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        primes.insert(a[i]);
    }
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    map<int, int> lcm;
    for (int i = 0; i < n; ++i)
        lcm[a[i]] = b[i];

    int m;
    cin >> m;
    vector<int> c(m), d(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> c[i];
        primes.insert(c[i]);
    }
    for (int i = 0; i < m; ++i)
        cin >> d[i];

    map<int, int> gcd;
    for (int i = 0; i < m; ++i)
        gcd[c[i]] = d[i];

    int ans = 1;
    for (int i : primes)
    {
        if (gcd[i] > lcm[i])
            ans = 0;
        if (gcd[i] < lcm[i])
            ans = (2 * ans) % mod;
    }
    cout << ans << '\n';
}