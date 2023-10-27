#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    int result = 1;
    for (int day = 0; day < k; ++day)
    {
        if (a[n - 1] > result + n - 1)
        {
            int i = 0;
            for (; i < n && a[i] <= result + i; ++i)
                ;
            result += i;
        }
        else
            result += n;
    }
    cout << result << '\n';
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