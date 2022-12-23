#include <bits\stdc++.h>

using namespace std;

using i64 = int64_t;

int main()
{
    i64 n, k;
    cin >> n >> k;
    i64 t = 0;
    i64 now_installed = 1;
    while (now_installed < n && now_installed <= k)
    {
        now_installed <<= 1;
        ++t;
    }
    n -= now_installed;
    if (n > 0)
        t += (n / k) + (n % k != 0);
    cout << t << '\n';
}