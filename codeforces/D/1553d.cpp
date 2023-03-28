#include <bits/stdc++.h>

using namespace std;

void solve()
{
    string s, t;
    cin >> s >> t;
    int ns = s.size(), nt = t.size();
    if (nt > ns)
    {
        cout << "NO\n";
        return;
    }
    int i = (nt - ns) % 2, j = 0;
    while (i < ns && j < nt)
    {
        if (s[i] == t[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i += 2;
        }
    }
    if (j == nt)
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