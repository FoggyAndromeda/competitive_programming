#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const int mod = 1e9 + 7;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> fs(2, vector<int>(a + 1, 0));
    vector<vector<int>> ss(2, vector<int>(b + 1, 0));
    fs[0][1] = 1;
    ss[0][1] = 1;
    for (int i = 2; i <= n; ++i)
    {
        for (int j = 2; j <= a; ++j)
            fs[1][j] = fs[0][j - 1];
        for (int j = 2; j <= b; ++j)
            ss[1][j] = ss[0][j - 1];
        for (int j = 1; j <= b; ++j)
            fs[1][1] = (fs[1][1] + ss[0][j]) % mod;
        for (int j = 1; j <= a; ++j)
            ss[1][1] = (ss[1][1] + fs[0][j]) % mod;
        fs[0] = fs[1];
        ss[0] = ss[1];
        for (int j = 1; j <= a; ++j)
            fs[1][j] = 0;
        for (int j = 1; j <= b; ++j)
            ss[1][j] = 0;
    }
    int ans = 0;
    for (int i = 1; i <= a; ++i)
        ans = (ans + fs[0][i]) % mod;
    for (int i = 1; i <= b; ++i)
        ans = (ans + ss[0][i]) % mod;
    cout << ans << '\n';
}