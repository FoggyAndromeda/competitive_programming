#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i)
    {
        int j;
        cin >> j;
        a[j - 1] = i;
    }
    for (int i = 0; i < n; ++i)
    {
        int j;
        cin >> j;
        b[j - 1] = i;
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < n; ++i)
        ++mp[(b[i] - a[i] + n) % n];
    int ans = 0;
    for (auto [d, i] : mp)
        ans = max(ans, i);
    cout << ans << '\n';
}