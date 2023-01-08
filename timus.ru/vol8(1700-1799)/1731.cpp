#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
    {
        cout << i << ' ';
    }
    cout << '\n';
    for (int j = 1; j <= m; ++j)
    {
        cout << (n + 1) * j << ' ';
    }
    cout << '\n';
}