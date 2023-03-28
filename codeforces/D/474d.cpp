#include <bits/stdc++.h>

using namespace std;
const int mod = 1e9 + 7;
const int maxn = 1e5 + 2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int t, k;
    cin >> t >> k;
    vector<int> dp(maxn);
    dp[0] = 1;
    dp[1] = 1 + (k == 1);
    for (int i = 2; i < maxn; ++i)
    {
        if (i < k)
            dp[i] = dp[i - 1];
        else
            dp[i] = (0ll + dp[i - 1] + dp[i - k]) % mod;
    }
    vector<int> prefs(maxn, 0);
    prefs[0] = 1;
    for (int i = 0; i < maxn; ++i)
        prefs[i] = (0ll + prefs[i - 1] + dp[i]) % mod;
    while (t-- > 0)
    {
        int a, b;
        cin >> a >> b;
        cout << (0ll + prefs[b] - prefs[a - 1] + mod) % mod << '\n';
    }
}