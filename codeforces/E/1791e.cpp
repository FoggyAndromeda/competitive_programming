#include <bits/stdc++.h>

using namespace std;
#define int int64_t

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0, cnt_negative = 0, minabs = 0x7fffffff;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        sum += abs(a[i]);
        cnt_negative += a[i] < 0;
        minabs = min(minabs, abs(a[i]));
    }
    if (cnt_negative % 2 == 0)
        cout << sum << '\n';
    else
        cout << sum - 2 * minabs << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}