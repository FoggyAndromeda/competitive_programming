#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    string type;
    cin >> type;
    i64 n;
    cin >> n;
    vector<i64> a;
    for (i64 i = 1 << 24; i > 0; i >>= 8)
    {
        i64 l = 0, r = 256;
        while (r - l > 1)
        {
            i64 m = (l + r) >> 1;
            if (i * m <= n)
                l = m;
            else
                r = m;
        }
        a.push_back(l);
        n -= i * l;
    }
    i64 ans = 0;
    for (i64 i = 0; i < 4; ++i)
    {
        ans += a[i] * (1 << (8 * i));
    }
    cout << ans;
}