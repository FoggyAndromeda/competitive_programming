#include <bits/stdc++.h>

using namespace std;

/*
x + a + (a - 1) + (a - 2) + ... + 1 = kn, a in [1, p]
x + (a + 1) * a / 2 = kn
2x + (a + 1) * a = 2kn
2x + a^2 + a = 2kn
a^2 + a + 2(x - kn) = 0
a = 1 +- sqrt(1 - 8(x - kn)) / 2
*/

void solve()
{
    int n, x, p;
    cin >> n >> x >> p;
    bool ans = 0;
    for (int i = 1; i <= min(p, 2 * n); ++i)
    {
        if ((x + (i + 1) * i / 2) % n == 0)
        {
            // clog << i << ' ';
            ans = 1;
        }
    }
    // clog << '\n';
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
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