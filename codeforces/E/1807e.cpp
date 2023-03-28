#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> pref(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        int now;
        cin >> now;
        pref[i] = pref[i - 1] + now;
    }
    int l = 0, r = n + 1;
    while (r - l > 1)
    {
        int m = (l + r) >> 1;
        cout << "? " << m << ' ';
        for (int i = 1; i <= m; ++i)
            cout << i << ' ';
        int mass;
        cin >> mass;
        if (mass > pref[m])
            r = m;
        else
            l = m;
    }
    cout << "! " << r << '\n';
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}