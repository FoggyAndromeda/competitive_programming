#include <bits/stdc++.h>

using namespace std;

/*
1: 1
2: -
3: -
4: 2 4 1 3
5: 1 3 5 2 4
6: 1 3 5 2 6 4
7: 1 3 5 7 4 6 2
8: 1 3 5 7 4 8 6 2
9: 1 3 5 7 9 6 8 4 2
0: 1 2 3 7 9 6 0 8 4 2
*/

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << "1\n";
        return;
    }
    if (n == 2 || n == 3)
    {
        cout << "-1\n";
        return;
    }
    if (n == 4)
    {
        cout << "2 4 1 3\n";
        return;
    }
    int maxodd = n - (n % 2 == 0);
    for (int i = 1; i <= maxodd; i += 2)
        cout << i << ' ';
    // jump -3
    cout << maxodd - 3 << ' ';
    // jump +4 if n even
    if (n % 2 == 0)
        cout << maxodd + 1 << ' ';
    for (int i = maxodd - 1; i > 0; i -= 2)
    {
        if (i == maxodd - 3)
            continue;
        else
            cout << i << ' ';
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
