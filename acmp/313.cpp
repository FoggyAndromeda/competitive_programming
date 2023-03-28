#pragma GCC optimize("O3,unroll-loops")
#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> previous(1000, -1);
    int ans = 0;
    int now;
    for (int i = 0; i < n; ++i)
    {
        cin >> now;
        if (previous[now] != -1)
            ans = max(ans, i - previous[now]);
        previous[now] = i;
    }
    cout << ans;
}