#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    if (n * a != m * b)
    {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    // 1..a..10..b..0
    vector<int> line(m, 0);
    for (int i = 0; i < a; ++i)
        line[i] = 1;

    int delta = m - a;
    int shift = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
            cout << line[(j + shift) % m];
        cout << '\n';
        shift += delta;
    }
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