#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int res = 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        res ^= a[i];
    }
    // if a can become [k, k] or [k ... k] (even len)
    if (res == 0)
    {
        cout << "YES\n";
        return;
    }
    // if a can become [k, k ... k] (odd len)
    int nowres = 0, count = 0;
    for (int i = 0; i < n; ++i)
    {
        nowres ^= a[i];
        if (nowres == res)
        {
            nowres = 0;
            ++count;
        }
    }
    if (count > 1 && nowres == 0 && count % 2 == 1)
        cout << "YES\n";
    else
        cout << "NO\n";
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