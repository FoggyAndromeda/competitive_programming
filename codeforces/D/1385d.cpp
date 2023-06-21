#include <bits/stdc++.h>

using namespace std;

int ans(string &s, int l, int r, char c)
{
    // clog << l << ' ' << r << ' ' << c << '\n';
    if (l == r)
        return s[l] != c;
    int m = (l + r) >> 1;
    int left_half = 0, right_half = 0;
    for (int i = l; i <= m; ++i)
        left_half += s[i] != c;
    for (int i = m + 1; i <= r; ++i)
        right_half += s[i] != c;
    return min(left_half + ans(s, m + 1, r, c + 1), right_half + ans(s, l, m, c + 1));
}

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    cout << ans(s, 0, n - 1, 'a') << '\n';
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