#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

#define double long double
#define int int64_t

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;

    unordered_map<int, int> counter;
    double ans = 0;
    double prefix = 0;

    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        ans += i * a;
        ans -= prefix;
        ans += counter[a + 1];
        ans -= counter[a - 1];
        prefix += a;
        ++counter[a];
    }
    cout << fixed << setprecision(0);
    cout << ans << '\n';
}
