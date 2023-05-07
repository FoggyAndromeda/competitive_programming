#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int l = 0, r = 1e9;

    // |a[i - 1] - x| <= |a[i] - x|
    // Метод рационализации делает брррррр
    // (a[i - 1] - x - a[i] + x)(a[i - 1] - x + a[i] - x) <= 0
    // (a[i - 1] - a[i])(a[i - 1] + a[i] - 2x) <= 0
    //
    // if a[i - 1] - a[i] > 0:
    //   -2x <= -a[i - 1] - a[i] --> 2x >= a[i - 1] + a[i]
    // if a[i - 1] - a[i] < 0:
    //   ... --> 2x <= a[i - 1] + a[i]

    for (int i = 1; i < n; ++i)
    {
        if (a[i - 1] == a[i])
            continue;

        if (a[i - 1] - a[i] > 0)
            l = max(l, (a[i - 1] + a[i]) / 2 + (a[i - 1] + a[i]) % 2);
        else
            r = min(r, (a[i - 1] + a[i]) >> 1);
    }
    if (r < l)
    {
        cout << "-1\n";
        return;
    }
    cout << l << '\n';
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