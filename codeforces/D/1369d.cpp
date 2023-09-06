#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 2'000'001;
const int mod = 1e9 + 7;
int prec[maxn][2];

void precalc()
{
    prec[0][0] = prec[0][0] = 0;
    prec[1][0] = prec[1][1] = 0;
    prec[2][0] = prec[2][1] = 0;
    for (int i = 3; i < maxn; ++i)
    {
        prec[i][0] = 2ll * max(prec[i - 2][0], prec[i - 2][1]) + max(prec[i - 1][0], prec[i - 1][1]);
        prec[i][0] %= mod;
        prec[i][1] = 2ll * prec[i - 2][0] + prec[i - 1][0] + 1ll;
        prec[i][1] %= mod;
    }
}

void solve()
{
    int n;
    cin >> n;
    cout << (4ll * max(prec[n][0], prec[n][1])) % mod << '\n';
}

int32_t main()
{
    precalc();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}