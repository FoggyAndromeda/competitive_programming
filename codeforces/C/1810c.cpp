#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

void solve()
{
    i64 n, c, d;
    cin >> n >> c >> d;
    vector<i64> a(n);
    for (i64 i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    auto uni = unique(a.begin(), a.end());
    i64 constdel = a.end() - uni;
    a.erase(uni, a.end());

    i64 ans = c * n + d; // delete all and push 1
    i64 shouldbeinserted = (a[0] - 1) * d;
    for (i64 i = 1; i < a.size(); ++i) // permutation from 0 to i - 1
    {
        // clog << shouldbeinserted << ' ' << c * (n - i) << '\n';
        ans = min(ans, shouldbeinserted + c * (i64(a.size()) - i + constdel));
        shouldbeinserted += (a[i] - a[i - 1] - 1) * d;
    }
    ans = min(ans, shouldbeinserted + c * constdel);
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