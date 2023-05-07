#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> counter;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        ++counter[a[i]];
    }
    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int ans = 0;
    for (auto elem : a)
        while (counter[elem] > 0)
        {
            int k = elem;
            ++ans;
            while (counter.find(k) != counter.end() && counter[k] > 0)
            {
                --counter[k];
                ++k;
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