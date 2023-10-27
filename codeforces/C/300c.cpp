#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e6 + 1;
const int mod = 1e9 + 7;

vector<int> fact(maxn);
vector<int> invfact(maxn);

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

void calc_fact()
{
    fact[0] = 1;
    for (int i = 1; i < maxn; ++i)
        fact[i] = (fact[i - 1] * i) % mod;
}

void calc_invfact()
{
    invfact[maxn - 1] = binpow(fact[maxn - 1], mod - 2);
    for (int i = maxn - 2; i > -1; --i)
        invfact[i] = (invfact[i + 1] * (i + 1)) % mod;
}

int cnk(int n, int k)
{
    int res = fact[n];
    res = (res * invfact[k]) % mod;
    res = (res * invfact[n - k]) % mod;
    return res;
}

bool check(int n, int a, int b)
{
    bool result = true;
    while (n > 0)
    {
        result = result && (n % 10 == a || n % 10 == b);
        n /= 10;
    }
    return result;
}

int32_t main()
{
    calc_fact();
    calc_invfact();
    int a, b, n;
    cin >> a >> b >> n;
    int ans = 0;
    for (int i = 0; i <= n; ++i)
    {
        int j = n - i;
        if (check(a * i + b * j, a, b))
            ans = (ans + cnk(n, i)) % mod;
    }
    cout << ans << '\n';
}
