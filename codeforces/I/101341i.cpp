#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

#define int int64_t

#define mod 1'000'000'007ll

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n)), b(n, vector<int>(n)), c(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> b[i][j];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> c[i][j];

    vector<int> random_vector(n);

    bool ans = true;

    for (int test = 0; test < 20; ++test)
    {
        for (int i = 0; i < n; ++i)
            random_vector[i] = rand();

        vector<int> resb(n), resab(n), resc(n);

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                resb[i] = (resb[i] + b[i][j] * random_vector[j]) % mod;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                resab[i] = (resab[i] + a[i][j] * resb[j]) % mod;

        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                resc[i] = (resc[i] + c[i][j] * random_vector[j]) % mod;

        for (int i = 0; i < n; ++i)
            if (resab[i] != resc[i])
                ans = false;
    }

    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
}