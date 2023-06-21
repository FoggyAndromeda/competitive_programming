#include <bits/stdc++.h>

using namespace std;

int binpow(int a, int n, int mod)
{
    int res = 1;
    while (n > 0)
    {
        if (n & 1)
            res = (1ll * res * a) % mod;
        a = (1ll * a * a) % mod;
        n >>= 1;
    }
    return res;
}

void solve()
{
    int n;
    cin >> n;
    int p, q;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            p = i;
            q = n / i;
            break;
        }
    int a = q * binpow(q, p - 2, p);
    int b = 1 - a + n;
    if (b < a)
        swap(a, b);
    cout << "0 1 " << a << ' ' << b << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}