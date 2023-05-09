#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve()
{
    int n;
    cin >> n;
    stack<int> ans;
    while (n > 0)
    {
        ans.push(n % 9);
        n /= 9;
    }
    while (!ans.empty())
    {
        cout << ans.top() + (ans.top() >= 4);
        ans.pop();
    }
    cout << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    while (n-- > 0)
        solve();
}