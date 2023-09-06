#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    bool all_same = true;
    bool have_double = false;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        all_same = all_same && (i == 0 || a[i] == a[i - 1]);
        have_double = have_double || (i > 0 && a[i] == a[i - 1]);
    }
    have_double = have_double || (a[0] == a[n - 1]);
    if (all_same)
    {
        cout << "1\n";
        for (int i = 0; i < n; ++i)
            cout << "1 ";
        cout << '\n';
        return;
    }
    if (n % 2 == 0)
    {
        cout << "2\n";
        for (int i = 0; i < n; ++i)
            cout << (i % 2) + 1 << ' ';
        cout << '\n';
        return;
    }
    if (have_double)
    {
        cout << "2\n";
        int delta = 0;
        for (int i = 0; i < n; ++i)
        {
            if (delta == 0 && i > 0 && a[i] == a[i - 1])
                ++delta;
            cout << ((i + delta) % 2) + 1 << ' ';
        }
        cout << '\n';
        return;
    }
    cout << "3\n";
    for (int i = 0; i < n - 1; ++i)
        cout << (i % 2) + 1 << ' ';
    cout << "3\n";
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