#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 n, q;
    cin >> n >> q;
    vector<i64> a(n);
    for (i64 i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<i64> poi64s(n + 1, 0);
    for (i64 i = 0; i < q; ++i)
    {
        i64 l, r;
        cin >> l >> r;
        --l;
        --r;
        ++poi64s[l];
        --poi64s[r + 1];
    }
    poi64s.pop_back();
    for (i64 i = 1; i < n; ++i)
        poi64s[i] += poi64s[i - 1];
    // for (i64 i : poi64s)
    //     clog << i << ' ';
    // clog << '\n';
    sort(poi64s.begin(), poi64s.end());
    i64 ans = 0;
    for (i64 i = 0; i < n; ++i)
        ans += poi64s[i] * a[i];
    cout << ans << '\n';
}