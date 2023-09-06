#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;

vector<int> primes;
const int maxn = 4'000;

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

int main()
{
    precalc();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> ans(n);
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        int md = -1;
        for (int j = 0; j < primes.size(); ++j)
            if (a % primes[j] == 0)
            {
                md = primes[j];
                break;
            }
        if (md == -1)
            md = a;
        int maxd = a;
        while (maxd % md == 0)
            maxd /= md;
        if (maxd == 1)
            ans[i] = {-1, -1};
        else
            ans[i] = {md, maxd};
    }
    for (int i = 0; i < n; ++i)
        cout << ans[i].first << ' ';
    cout << '\n';
    for (int i = 0; i < n; ++i)
        cout << ans[i].second << ' ';
}