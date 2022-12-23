#include <bits/stdc++.h>

using namespace std;

bool is_prime(int x)
{
    if (x % 2 == 0)
        return false;
    for (int i = 3; i * i <= x; i += 2)
        if (x % i == 0)
            return false;
    return true;
}

const int m = 1e9 + 9;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> dp(n - 1, vector<int>(100, 0));
    for (int i = 10; i < 100; ++i)
        dp[0][i] = 1;
    for (int i = 1; i < n - 1; ++i)
        for (int j = 0; j < 10; ++j)
            for (int k = 10; k < 100; ++k)
                if (is_prime(10 * k + j))
                    dp[i][10 * (k % 10) + j] = (dp[i][10 * (k % 10) + j] + dp[i - 1][k]) % m;
    int ans = 0;
    for (int i = 0; i < 100; ++i)
        ans = (ans + dp[n - 2][i]) % m;
    cout << ans << '\n';
}