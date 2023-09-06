#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int binpow(int a, int n)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

const int maxn = int(sqrt(2e5)) + 2;
vector<int> primes = []()
{
    vector<bool> prime(maxn, true);
    prime[0] = false;
    prime[1] = false;
    for (int64_t i = 2; i < maxn; ++i)
        if (prime[i])
            for (int64_t j = i * i; j < maxn; j += i)
                prime[j] = false;
    vector<int> res;
    res.reserve(maxn / 32);
    for (int i = 0; i < maxn; ++i)
        if (prime[i])
            res.push_back(i);
    return res;
}();

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int ans = 1;
    vector<int> powers(n);
    for (int p : primes)
    {
        fill(powers.begin(), powers.end(), 0);
        for (int i = 0; i < n; ++i)
        {
            while (a[i] % p == 0)
            {
                ++powers[i];
                a[i] /= p;
            }
        }
        sort(powers.begin(), powers.end());

        ans *= binpow(p, powers[1]);
    }
    map<int, int> cnt;
    for (int i : a)
        ++cnt[i];
    for (auto [k, v] : cnt)
    {
        // clog << k << ' ' << v << '\n';
        if (v > n - 2)
            ans *= k;
    }
    cout << ans << '\n';
}