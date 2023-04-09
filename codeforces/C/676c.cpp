#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    int ans = 0;
    for (char c = 'a'; c < 'c'; ++c)
    {
        // clog << '\n';
        vector<int> prefs(n);
        for (int i = 0; i < n; ++i)
            prefs[i] = s[i] == c;
        for (int i = 1; i < n; ++i)
            prefs[i] += prefs[i - 1];

        for (int i = 0; i < n; ++i)
        {
            if (prefs[i] <= k)
            {
                ans = max(ans, i + 1);
                continue;
            }

            int l = 0, r = i;
            while (r - l > 1)
            {
                int m = (l + r) >> 1;
                if (prefs[i] - prefs[m] <= k)
                    r = m;
                else
                    l = m;
            }
            // clog << r << ' ' << i << '\n';
            ans = max(ans, i - r + (s[r] != c));
        }
    }
    cout << ans << '\n';
}
