#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> ss(n);
    for (int i = 0; i < n; ++i)
        cin >> ss[i];
    string ans = ss[0];

    for (int i = 0; i < m; ++i)
    {
        char init_char = ans[i];
        for (ans[i] = 'a'; ans[i] <= 'z'; ++ans[i])
        {
            bool all_less = true;
            for (int j = 1; j < n; ++j)
            {

                int cnt = 0;
                for (int k = 0; k < m; ++k)
                    cnt += ss[j][k] != ans[k];
                all_less &= cnt < 2;
            }
            if (all_less)
            {
                cout << ans << '\n';
                return;
            }
        }
        ans[i] = init_char;
    }
    cout << "-1\n";
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