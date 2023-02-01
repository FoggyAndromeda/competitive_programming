#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    int r;
    cin >> r;
    i64 ans = 0;
    for (int i = 0; i <= r; ++i)
    {
        ans += ceill(sqrtl(r * r - i * i));
    }
    cout << 4 * ans << '\n';
}