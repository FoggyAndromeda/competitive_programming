#include <bits/stdc++.h>

using namespace std;

#define mod 100'000'000

int main()
{
    int n1, n2, k1, k2;
    cin >> n1 >> n2 >> k1 >> k2;
    map<tuple<int, int, int, int>, int> visited;
    function<int(int, int, int, int)> dp = [&](int cnt1, int cnt2, int cntlast, int last)
    {
        if (visited.find({cnt1, cnt2, cntlast, last}) != visited.end())
            return visited[{cnt1, cnt2, cntlast, last}];
        if (cnt1 > n1)
            return 0;
        if (cnt2 > n2)
            return 0;
        if (cnt1 == n1 && cnt2 == n2)
            return 1;
        int ans = 0;
        if (last == 0)
        {
            if (cntlast < k1)
                ans = (ans + dp(cnt1 + 1, cnt2, cntlast + 1, 0)) % mod;
            ans = (ans + dp(cnt1, cnt2 + 1, 1, 1)) % mod;
        }
        if (last == 1)
        {
            if (cntlast < k2)
                ans = (ans + dp(cnt1, cnt2 + 1, cntlast + 1, 1)) % mod;
            ans = (ans + dp(cnt1 + 1, cnt2, 1, 0)) % mod;
        }
        visited[{cnt1, cnt2, cntlast, last}] = ans;
        return ans;
    };
    cout << dp(0, 0, 0, 0) << '\n';
}