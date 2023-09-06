#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int x;
    cin >> x;
    vector<int> result;
    int i = 0;
    for (; i < 30; ++i)
    {
        if (((x >> i) & 1) == 0)
            continue;
        result.push_back(x);
        // clog << x << ' ' << (1 << i) << '\n';
        if (x == (1 << i))
            break;
        x -= 1 << i;
    }
    for (--i; i >= 0; --i)
    {
        x -= 1 << i;
        result.push_back(x);
    }
    cout << result.size() << '\n';
    for (int j : result)
        cout << j << ' ';
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