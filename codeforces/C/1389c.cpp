#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    int n = s.size(), ans = n;
    for (int i = 0; i < 10; ++i)
    {
        for (int j = 0; j < 10; ++j)
        {
            int nowcnt = 0;
            for (int k = 0; k < n; ++k)
            {
                if ((nowcnt % 2 == 0 && s[k] - '0' == i) || (nowcnt % 2 == 1 && s[k] - '0' == j))
                    ++nowcnt;
            }
            // clog << i << j << ' ' << nowcnt << '\n';
            if (i == j || (i != j && nowcnt % 2 == 0))
                ans = min(ans, n - nowcnt);
        }
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