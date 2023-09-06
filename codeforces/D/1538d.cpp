#include <bits/stdc++.h>

using namespace std;

#define int int64_t

vector<int> primes;
const int maxn = 1e5;

void precalc()
{
    vector<bool> is_prime(maxn, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 0; i < maxn; ++i)
        if (is_prime[i])
            for (int j = i * i; j < maxn; j += i)
                is_prime[j] = false;
    for (int i = 0; i < maxn; ++i)
        if (is_prime[i])
            primes.push_back(i);
}

void solve()
{
    int aa, bb, k;
    cin >> aa >> bb >> k;
    int max_moves = 0;
    int a = aa, b = bb;
    for (int i = 0; i < primes.size(); ++i)
    {
        while (a % primes[i] == 0)
        {
            a /= primes[i];
            ++max_moves;
        }
        while (b % primes[i] == 0)
        {
            b /= primes[i];
            ++max_moves;
        }
    }
    if (a != 1)
        ++max_moves;
    if (b != 1)
        ++max_moves;

    int min_moves;
    if (aa == bb)
        min_moves = 0;
    else if (__gcd(aa, bb) == aa || __gcd(aa, bb) == bb)
        min_moves = 1;
    else
        min_moves = 2;

    if (min_moves <= k && k <= max_moves && k == 1 && min_moves == 1)
        cout << "YES\n";
    else if (min_moves <= k && k <= max_moves && k != 1)
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    precalc();
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}