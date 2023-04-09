#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> ans(n, -1);
    int counter = 0;
    vector<stack<int>> sts(2);
    for (int i = 0; i < n; ++i)
    {
        int now = s[i] - '0';
        if (sts[1 - now].empty())
            ans[i] = counter++;
        else
        {
            ans[i] = ans[sts[1 - now].top()];
            sts[1 - now].pop();
        }
        sts[now].push(i);
    }
    cout << counter << '\n';
    for (auto elem : ans)
        cout << elem + 1 << ' ';
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