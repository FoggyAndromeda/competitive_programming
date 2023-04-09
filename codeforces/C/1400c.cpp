#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    int x;
    cin >> s >> x;
    int n = s.size();
    string res(n, '2');
    bool ok = true;

    for (int i = 0; i < x && i + x < n; ++i)
        res[i + x] = s[i];

    for (int i = n - x; i < n; ++i)
    {
        if (i - x < 0)
            continue;
        if (res[i - x] != '2' && res[i - x] != s[i])
            ok = false;
        res[i - x] = s[i];
    }

    for (int i = x; i < n - x; ++i)
        if (s[i] == '0')
        {
            if (res[i - x] == '1' || res[i + x] == '1')
                ok = false;
            res[i - x] = '0';
            res[i + x] = '0';
        }

    for (int i = x; i < n - x; ++i)
        if (s[i] == '1')
        {
            if (res[i - x] == '0' && res[i + x] == '0')
                ok = false;
            if (res[i - x] == '2')
                res[i - x] = '1';
            if (res[i + x] == '2')
                res[i + x] = '1';
        }

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1' && i - x < 0 && i + x >= n)
            ok = false;
        if (res[i] == '2')
            res[i] = '0';
    }

    if (ok)
        cout << res << '\n';
    else
        cout << "-1\n";
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