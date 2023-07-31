#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int sum_of_digits(int n)
{
    int res = 0;
    while (n > 0)
    {
        res += n % 10;
        n /= 10;
    }
    return res;
}

void solve()
{
    int n, s;
    cin >> n >> s;
    int now_sum = sum_of_digits(n);
    int divider = 1;
    int ans = 0;
    while (now_sum > s)
    {
        int now_digit = (n / divider) % 10;
        ans += (10 - now_digit) * divider;
        n += (10 - now_digit) * divider;
        now_sum = sum_of_digits(n);
        divider *= 10;
    }
    cout << ans << '\n';
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}