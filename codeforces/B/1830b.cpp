#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2,fma")

#include <bits/stdc++.h>

using namespace std;

vector<float> a(200'001), b(200'001);

void solve()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int ai;
        cin >> ai;
        a[i] = ai;
    }
    for (int i = 0; i < n; ++i)
    {
        int bi;
        cin >> bi;
        b[i] = bi;
    }
    int64_t ans = 0;
    for (int i = 1; i < n; ++i)
    {
        int an = 0;
        for (int j = 0; j < i; ++j)
            an += ((a[i] * a[j] - b[i]) == b[j]);
        ans += an;
    }
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