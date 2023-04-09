#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<double> p(n);
    for (int i = 0; i < n; ++i)
        cin >> p[i];

    vector<double> prev(n + 1, 0), now(n + 1, 0);

    prev[0] = 1 - p[0];
    prev[1] = p[0];
    for (int i = 1; i < n; ++i)
    {
        now[0] = prev[0] * (1 - p[i]);
        for (int j = 1; j <= n; ++j)
            now[j] = prev[j] * (1 - p[i]) + prev[j - 1] * p[i];
        prev = now;
    }

    double ans = 0;
    for (int i = n / 2 + 1; i <= n; ++i)
        ans += prev[i];

    cout << fixed << setprecision(10);
    cout << ans << '\n';
}