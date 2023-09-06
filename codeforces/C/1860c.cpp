#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    int ans = 0;

    int ml = 0x7fffffff, last_ans = 0x7fffffff;
    for (int i = 0; i < n; ++i)
    {
        int p;
        cin >> p;
        if (p > ml && p < last_ans)
        {
            ++ans;
            last_ans = p;
        }
        ml = min(ml, p);
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}