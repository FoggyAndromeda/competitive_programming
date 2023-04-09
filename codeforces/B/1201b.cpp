#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    int n;
    cin >> n;
    vector<i64> a(n);
    i64 res = 0;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        res += a[i];
    }
    sort(a.begin(), a.end());
    if (res % 2 == 0 && res - 2 * a[n - 1] >= 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}