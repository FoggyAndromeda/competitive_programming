#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main()
{
    int n, m, k;
    cin >> n >> m >> k;

    function<int(int)> calculate_less = [&](int x)
    {
        int res = 0;
        for (int i = 1; i <= n; ++i)
            res += min((x - 1) / i, m);
        return res;
    };

    int l = 0, r = n * m + 1;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if (calculate_less(m) < k)
            l = m;
        else
            r = m;
    }
    cout << l << '\n';
}