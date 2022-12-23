#include <bits\stdc++.h>

using namespace std;

int binpow(int a, int b, int mod)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
            res %= mod;
            --b;
        }
        a *= a;
        a %= mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n, m, y;
    cin >> n >> m >> y;
    bool found = false;
    for (int i = 1; i < m; ++i)
    {
        if (binpow(i, n, m) == y)
        {
            cout << i << ' ';
            found = true;
        }
    }
    if (!found)
        cout << "-1\n";
}