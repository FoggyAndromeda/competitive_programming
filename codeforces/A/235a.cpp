#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    i64 n;
    cin >> n;
    i64 ans = 1 + (n == 2);
    i64 cnt = n * (n - 1);
    for (i64 i = 1; i < n - 1; ++i)
        ans = max(ans, cnt * i / __gcd(cnt, i));
    cnt = (n - 1) * (n - 2);
    for (i64 i = 1; i < n - 2; ++i)
        ans = max(ans, cnt * i / __gcd(cnt, i));
    cout << ans << '\n';
}