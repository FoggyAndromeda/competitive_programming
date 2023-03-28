#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() > k)
    {
        cout << "-1\n";
        return;
    }
    while (a.size() < k)
    {
        a.push_back(a[0]);
    }
    cout << 10'000 / a.size() * a.size() << '\n';
    for (int i = 0; i < 10'000 / a.size() * a.size(); ++i)
        cout << a[i % a.size()] << ' ';
    cout << '\n';
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
