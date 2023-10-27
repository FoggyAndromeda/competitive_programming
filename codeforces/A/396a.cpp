#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 1e9 + 7;
const int maxn = 1e5;

vector<int> fact, inv_fact;

int binpow(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (res * a) % mod;
        n >>= 1;
        a = (a * a) % mod;
    }
    return res;
}

void precalc()
{
    fact.assign(maxn, 1);
    for (int i = 2; i < maxn; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
    inv_fact.assign(maxn, 1);
    inv_fact[maxn - 1] = binpow(fact[maxn - 1], mod - 2);
    for (int i = maxn - 2; i > -1; --i)
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % mod;
}

int cnk(int n, int k)
{
    int res = fact[n];
    res = (res * inv_fact[k]) % mod;
    res = (res * inv_fact[n - k]) % mod;
    return res;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    precalc();

    // for (int i = 0; i < maxn; ++i)
    //     clog << (fact[i] * inv_fact[i]) % mod << ' ';

    int n;
    cin >> n;
    map<int, int> primes;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        for (int i = 2; i * i <= a; ++i)
        {
            while (a % i == 0)
            {
                a /= i;
                ++primes[i];
            }
        }
        if (a != 1)
            ++primes[a];
    }
    int ans = 1;
    for (auto [pr, pw] : primes)
        ans = (ans * cnk(pw + n - 1, n - 1)) % mod;
    cout << ans << '\n';
}
