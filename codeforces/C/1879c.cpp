#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 2e5 + 1;
const int mod = 998244353;

vector<int> factorial(maxn);

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

void precalc()
{
    factorial[0] = factorial[1] = 1;
    for (int i = 2; i < maxn; ++i)
        factorial[i] = (factorial[i - 1] * i) % mod;
}

int cnk(int n, int k)
{
    int result = factorial[n];
    result = (result * binpow(factorial[n - k], mod - 2)) % mod;
    result = (result * binpow(factorial[k], mod - 2)) % mod;
    return result;
}

void solve()
{
    string s;
    cin >> s;
    vector<int> blocks;
    int cnt = 1;
    for (int i = 1; i < s.size(); ++i)
    {
        if (s[i] == s[i - 1])
        {
            ++cnt;
            continue;
        }
        blocks.push_back(cnt);
        cnt = 1;
    }
    blocks.push_back(cnt);
    int ans1 = 0;
    for (int i : blocks)
        ans1 += i - 1;
    int to_place = ans1;
    int ans2 = 1;

    for (int b : blocks)
    {
        ans2 *= (factorial[b] * cnk(to_place, b - 1)) % mod;
        ans2 %= mod;
        to_place -= b - 1;
    }
    cout << ans1 << ' ' << ans2 << '\n';
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
