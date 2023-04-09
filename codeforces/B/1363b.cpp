#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> ones(n, 0), zeroes(n, 0);
    for (int i = 0; i < n; ++i)
    {
        ones[i] = s[i] - '0';
        zeroes[i] = 1 - ones[i];
    }
    for (int i = 1; i < n; ++i)
    {
        ones[i] += ones[i - 1];
        zeroes[i] += zeroes[i - 1];
    }
    int ans = min(ones[n - 1], zeroes[n - 1]);
    for (int i = 0; i < n; ++i)
    {
        ans = min(ans, ones[i] + zeroes[n - 1] - zeroes[i]);
        ans = min(ans, zeroes[i] + ones[n - 1] - ones[i]);
    }
    cout << ans << '\n';
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