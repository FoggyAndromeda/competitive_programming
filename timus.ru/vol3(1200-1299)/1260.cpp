#include <bits/stdc++.h>

using namespace std;

// oeis: A038718
// TODO: write another dp solution

int main()
{
    vector<int> dp(60);
    dp[1] = dp[2] = 1;
    dp[3] = 2;
    for (int i = 4; i < 56; ++i)
        dp[i] = dp[i - 1] + dp[i - 3] + 1;

    int n;
    cin >> n;
    cout << dp[n] << '\n';
}