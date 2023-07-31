#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2")

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = -0; i < n; ++i)
    {
        cin >> a[i];
        a[i] %= m;
    }
    bitset<1024> result;
    for (int i = 0; i < n; ++i)
    {

        result |= (result << a[i]) | (result >> (m - a[i]));
        result.set(a[i], 1);

        // for (int j = 0; j < m; ++j)
        //     clog << result[j];
        // clog << '\n';
    }
    if (result[0])
        cout << "YES\n";
    else
        cout << "NO\n";
}