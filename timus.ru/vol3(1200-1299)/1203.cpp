#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> beginings(30'001);
    for (int i = 0; i < n; ++i)
    {
        int b, e;
        cin >> b >> e;
        beginings[e].push_back(b);
    }
    vector<int> dp(30'001, 0);
    for (int i = 1; i < 30'001; ++i)
    {
        dp[i] = dp[i - 1];
        for (int b : beginings[i])
        {
            dp[i] = max(dp[i], dp[b - 1] + 1);
        }
    }
    cout << dp[30'000] << '\n';
}