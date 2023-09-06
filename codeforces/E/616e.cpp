#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;

int binpow(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        n >>= 1;
    }
    return res;
}

const int inv2 = binpow(2, mod - 2);

int sum(int a)
{
    a %= mod;
    int res = a * (a + 1);
    res %= mod;
    res = (res * inv2) % mod;
    return res;
}

int32_t main()
{
    int n, m;
    cin >> n >> m;

    int ans = (n % mod) * (m % mod);
    ans %= mod;

    m = min(n, m);
    int mini = m;
    for (int i = 1; i * i <= n; ++i)
    {
        int l = n / (i + 1), r = min(n / i, m);
        if (l >= r)
            continue;
        mini = l;

        int s = (sum(r) - sum(l) + mod) % mod;

        ans = (mod + ans - (i * s) % mod) % mod;
    }
    for (int i = 1; i <= mini; ++i)
        ans = (mod + ans - (i * (n / i)) % mod) % mod;

    cout << ans << '\n';
}