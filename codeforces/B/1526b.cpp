#include <bits/stdc++.h>

using namespace std;

/*
11a + 111b = n
b = n mod 11
*/

void solve()
{
    int n;
    cin >> n;
    int b = n % 11;
    int a = (n - 111 * b) / 11;
    if (a >= 0 && 11 * a + 111 * b == n)
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