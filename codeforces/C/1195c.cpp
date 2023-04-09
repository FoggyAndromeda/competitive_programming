#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
        cin >> b[i];
    vector<int> now(2), prev(2);
    prev[0] = a[0];
    prev[1] = b[0];
    for (int i = 1; i < n; ++i)
    {
        now[0] = max(prev[0], prev[1] + a[i]);
        now[1] = max(prev[1], prev[0] + b[i]);
        prev = now;
    }
    cout << max(prev[0], prev[1]) << '\n';
}