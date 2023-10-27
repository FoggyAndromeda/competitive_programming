#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int mod = 998244353;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];

    int ans = 0;
    for (int bit = 0; bit < 32; ++bit)
    {
        int sum_odd_ind = 0;
        int cnt_odd = 0;
        int sum_even_ind = 0;
        int cnt_even = 1;
        int cnt = 0;
        int now_ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            cnt += (a[i] >> bit) & 1;
            // clog << cnt << ' ' << cnt_odd << ' ' << sum_odd_ind << ' ' << cnt_even << ' ' << sum_even_ind << '\n';
            if (cnt % 2 == 0)
            {
                now_ans += cnt_odd * i - sum_odd_ind;
                now_ans %= mod;
                ++cnt_even;
                sum_even_ind += i;
            }
            else
            {
                now_ans += cnt_even * i - sum_even_ind;
                now_ans %= mod;
                ++cnt_odd;
                sum_odd_ind += i;
            }
        }
        // clog << bit << ' ' << now_ans << '\n';
        ans += now_ans * (1 << bit);
        ans %= mod;
    }
    cout << ans << '\n';
}