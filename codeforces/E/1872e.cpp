#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    string s;
    cin >> s;
    int ones = 0;
    int zeroes = 0;
    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '0')
            zeroes ^= a[i];
        else
            ones ^= a[i];
    }
    for (int i = 1; i < n; ++i)
        a[i] ^= a[i - 1];
    int q;
    cin >> q;
    while (q-- > 0)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int l, r;
            cin >> l >> r;
            --l;
            --r;
            int sub = 0;
            if (l == 0)
                sub = a[r];
            else
                sub = a[r] ^ a[l - 1];
            ones ^= sub;
            zeroes ^= sub;
        }
        else
        {
            int k;
            cin >> k;
            if (k == 1)
                cout << ones << ' ';
            else
                cout << zeroes << ' ';
        }
    }
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