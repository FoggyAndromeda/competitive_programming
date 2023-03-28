#include <bits/stdc++.h>

using namespace std;
const int INF = 0x7fffffff;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int a, b;
        cin >> a >> b;
        if (abs(a) == abs(b))
            cout << 2 * abs(a) << '\n';
        else
            cout << 2 * max(abs(a), abs(b)) - 1 << '\n';
    }
}