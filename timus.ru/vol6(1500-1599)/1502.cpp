#include <bits\stdc++.h>

using namespace std;
using ui64 = uint64_t;

int main()
{
    ui64 n;
    cin >> n;
    ui64 ans = 0;
    for (ui64 i = 0; i <= n; ++i)
    {
        for (ui64 j = i; j <= n; ++j)
        {
            ans += i + j;
        }
    }
    cout << ans << '\n';
}