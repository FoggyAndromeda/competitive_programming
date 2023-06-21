#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int32_t main()
{
    int k;
    cin >> k;
    string s;
    cin >> s;
    int n = s.size();

    if (k == 0)
    {
        int now_zeroes = 0;
        int ans = 0;
        for (int i = 0; i < n; ++i)
        {
            if (s[i] == '0')
                ++now_zeroes;
            else
            {
                ans += (now_zeroes * (now_zeroes + 1)) >> 1;
                now_zeroes = 0;
            }
        }
        ans += (now_zeroes * (now_zeroes + 1)) >> 1;
        cout << ans << '\n';
        return 0;
    }
    vector<int> ones = {0};
    for (int i = 0; i < n; ++i)
        if (s[i] == '1')
            ones.push_back(i + 1);
    ones.push_back(n + 1);
    int ans = 0;
    for (int i = 1; i + k < ones.size(); ++i)
    {
        ans += (ones[i] - ones[i - 1]) * (ones[i + k] - ones[i + k - 1]);
    }
    cout << ans << '\n';
}