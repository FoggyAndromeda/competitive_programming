#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        a[i] = (a[i] == i);
        pref[i] = a[i];
    }
    for (int i = 2; i <= n; ++i)
        pref[i] += pref[i - 1];

    int l = 1, r = n;
    while (a[l] == 1)
        ++l;
    while (a[r] == 1)
        --r;
    if (l >= r)
    {
        cout << "0\n";
        return;
    }
    if (pref[r] - pref[l] == 0)
        cout << "1\n";
    else
        cout << "2\n";
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