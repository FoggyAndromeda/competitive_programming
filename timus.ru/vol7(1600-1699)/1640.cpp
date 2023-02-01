#include <bits/stdc++.h>

using namespace std;
using ld = long double;

int main()
{
    cout << fixed << setprecision(9);
    int n;
    cin >> n;
    ld ans = 0;
    for (int i = 0; i < n; ++i)
    {
        ld x, y;
        cin >> x >> y;
        ans = max(ans, sqrtl(x * x + y * y));
    }
    cout << "0 0 " << ans << '\n';
}