#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    n = a.size();
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 2 * a[i]; j < a[a.size() - 1] + 2 * a[i]; j += a[i])
        {
            int l = -1, r = n;
            while (r - l > 1)
            {
                int m = (l + r) >> 1;
                if (a[m] >= j)
                    r = m;
                else
                    l = m;
            }
            ans = max(ans, a[l] - a[i] * (j / a[i] - 1));
        }
    }
    cout << ans << '\n';
}