#include <bits/stdc++.h>

using namespace std;

#define int int64_t

int get_ans(int n, int l, int r)
{
    if (l > r)
        return 0;
    // clog << n << ' ' << l << ' ' << r << '\n';
    int layer = (1ll << (__lg(n) + 1)) - 1;
    // clog << n << ' ' << __lg(n) << ' ' << layer << '\n';
    if (layer == 1)
        return n;
    int mid = 1 + layer / 2;
    if (mid >= l && mid <= r)
    {
        return get_ans(n / 2, l, mid - 1) + n % 2 + get_ans(n / 2, 1, r - mid);
    }
    if (mid < l)
    {
        return get_ans(n / 2, l - mid, r - mid);
    }
    if (mid > r)
    {
        return get_ans(n / 2, l, r);
    }
}

int32_t main()
{
    int n, l, r;
    cin >> n >> l >> r;
    cout << get_ans(n, l, r) << '\n';
}