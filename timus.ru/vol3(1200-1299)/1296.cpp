#include <bits\stdc++.h>

using namespace std;

using i64 = int64_t;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0 << '\n';
        exit(0);
    }
    vector<i64> prefs(n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        i64 now;
        cin >> now;
        prefs[i] = prefs[i - 1] + now;
    }
    i64 ans = max(0LL, prefs[1]);
    i64 min_pref = prefs[1];
    for (int i = 2; i <= n; ++i)
    {
        ans = max(ans, prefs[i] - min_pref);
        ans = max(ans, prefs[i]);
        min_pref = min(min_pref, prefs[i]);
    }
    cout << ans << '\n';
}