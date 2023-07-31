#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,bmi,bmi2")

#include <bits/stdc++.h>

using namespace std;

using vvb = vector<vector<bool>>;

int n;

void mult(vvb &f, vvb &s)
{
    vvb res(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            for (int k = 0; k < n; ++k)
                if (f[i][k] && s[k][j])
                {
                    res[i][j] = true;
                    break;
                }
    f = res;
}

void sum(vvb &f, vvb &s)
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            f[i][j] = f[i][j] || s[i][j];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    vvb init(n, vector<bool>(n));
    vvb tempinit(n, vector<bool>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
        {
            int k;
            cin >> k;
            init[i][j] = tempinit[i][j] = k > 0;
        }
    vvb s(n, vector<bool>(n, false));

    vvb power(n, vector<bool>(n, false));
    for (int i = 0; i < n; ++i)
        power[i][i] = true;

    int nt = n;
    while (nt > 0)
    {
        if (nt & 1)
            mult(power, tempinit);
        mult(tempinit, tempinit);
        nt >>= 1;
    }

    for (int i = n * (n - 1); i < n * (n + 1); ++i)
    {
        sum(s, power);
        mult(power, init);
    }

    bool ans = true;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            ans = ans && s[i][j];
    if (ans)
        cout << "Yes\n";
    else
        cout << "No\n";
}