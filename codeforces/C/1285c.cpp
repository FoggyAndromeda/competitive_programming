#include <bits/stdc++.h>

using namespace std;
#define int int64_t

int32_t main()
{
    int n;
    cin >> n;
    pair<int, int> ans{n, 1};
    for (int i = 2; i * i < n; ++i)
    {
        if (n % i == 0 && __gcd(i, n / i) == 1)
            ans = {n / i, i};
    }
    cout << ans.first << ' ' << ans.second << '\n';
}