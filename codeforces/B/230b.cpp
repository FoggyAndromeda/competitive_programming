#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define int int64_t

bool is_prime(int a)
{
    if (a == 1)
        return false;
    if (a == 2)
        return true;
    if (a % 2 == 0)
        return false;
    for (int i = 3; i * i <= a; i += 2)
        if (a % i == 0)
            return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    int rt = sqrt(n);
    if (rt * rt == n && is_prime(rt))
        cout << "YES\n";
    else
        cout << "NO\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}