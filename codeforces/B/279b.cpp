#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, t;
    cin >> n >> t;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 1; i < n; ++i)
        a[i] += a[i - 1];
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        if (a[i] <= t)
            ans = max(ans, i + 1);
        int l = 0, r = i;
        while (r - l > 1)
        {
            int m = (l + r) / 2;
            if (a[i] - a[m] <= t)
                r = m;
            else
                l = m;
        }
        if (a[i] - a[l] <= t)
            ans = max(ans, i - l);
        if (a[i] - a[r] <= t)
            ans = max(ans, i - r);
    }
    cout << ans << '\n';
}