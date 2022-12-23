#include <bits\stdc++.h>

using namespace std;

const int INFI = 1e9;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> pref_sums(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            int now;
            cin >> now;
            pref_sums[i][j] = pref_sums[i - 1][j] + pref_sums[i][j - 1] - pref_sums[i - 1][j - 1] + now;
        }
    }
    int ans = -INFI;
    for (int x1 = 1; x1 <= n; ++x1)
    {
        for (int x2 = x1; x2 <= n; ++x2)
        {
            for (int y1 = 1; y1 <= n; ++y1)
            {
                for (int y2 = y1; y2 <= n; ++y2)
                {
                    ans = max(ans, pref_sums[x2][y2] - pref_sums[x1 - 1][y2] - pref_sums[x2][y1 - 1] + pref_sums[x1 - 1][y1 - 1]);
                }
            }
        }
    }
    cout << ans << '\n';
}