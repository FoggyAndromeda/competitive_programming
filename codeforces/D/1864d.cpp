#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int left_boundaries[n] = {0};
    int right_boundaries[n] = {0};
    int sum[n];
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        sum[0] = left_boundaries[0] + right_boundaries[0];
        for (int i = 1; i < n; ++i)
            sum[i] = sum[i - 1] + left_boundaries[i] + right_boundaries[i];

        for (int i = 0; i < n; ++i)
        {
            if ((sum[i] + (s[i] - '0')) % 2 == 1)
            {
                ++ans;
                ++left_boundaries[i];
                if (i + 1 < n)
                    --right_boundaries[i + 1];
            }
        }
        left_boundaries[0] = left_boundaries[0] + left_boundaries[1];
        for (int i = 1; i < n - 1; ++i)
            left_boundaries[i] = left_boundaries[i + 1];
        left_boundaries[n - 1] = 0;

        for (int i = n - 1; i > 0; --i)
            right_boundaries[i] = right_boundaries[i - 1];
        right_boundaries[0] = 0;
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