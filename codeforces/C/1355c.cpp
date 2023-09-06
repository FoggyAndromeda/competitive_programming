#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int maxn = 1e6 + 1;

int32_t main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    vector<int> ans(maxn);
    for (int x = a; x <= b; ++x)
    {
        ++ans[x + b];
        --ans[x + c + 1];
    }
    for (int i = 1; i < maxn; ++i)
        ans[i] += ans[i - 1];
    for (int i = 1; i < maxn; ++i)
        ans[i] += ans[i - 1];

    int res = 0;
    for (int z = c; z <= d; ++z)
        res += ans[maxn - 1] - ans[z];
    cout << res << '\n';
}