#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s;
    cin >> s;
    queue<int> odd, even;
    for (char c : s)
    {
        if ((c - '0') & 1)
            odd.push(c - '0');
        else
            even.push(c - '0');
    }
    while (!odd.empty() && !even.empty())
    {
        if (odd.front() < even.front())
        {
            cout << odd.front();
            odd.pop();
        }
        else
        {
            cout << even.front();
            even.pop();
        }
    }
    while (!odd.empty())
    {
        cout << odd.front();
        odd.pop();
    }
    while (!even.empty())
    {
        cout << even.front();
        even.pop();
    }
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