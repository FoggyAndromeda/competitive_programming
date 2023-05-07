#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void solve()
{
    int q;
    cin >> q;
    int l = -1, r = 1e18;
    while (q-- > 0)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            int a, b, n;
            cin >> a >> b >> n;
            // height max a * n - b * (n - 1)
            // height min a * (n - 1) - b * (n - 2) + 1
            int minh, maxh;
            if (n == 1)
            {
                minh = 1;
                maxh = a;
            }
            else
            {
                minh = a * (n - 1) - b * (n - 2) + 1;
                maxh = a * n - b * (n - 1);
            }
            if (maxh < l || minh > r)
            {
                cout << "0 ";
                continue;
            }
            cout << "1 ";
            l = max(l, minh);
            r = min(r, maxh);
        }
        else
        {
            int a, b;
            cin >> a >> b;
            if (l == -1)
            {
                cout << "-1 ";
                continue;
            }
            //
            // (n - 1) * a - (n - 2) * b < l <= n * a - (n - 1) * b
            // na - a - nb + 2b < l <= na - nb + b
            // n * (a - b) - a + 2b < l <= n * (a - b) + b
            // n * (a - b) - (a - b) < l - b <= n * (a - b)
            // (n - 1) < (l - b) / (a - b) <= n
            // n = (l - b) / (a - b) + ((l - b) % (a - b) != 0)
            //
            int lp = (l - b) / (a - b) + ((l - b) % (a - b) != 0),
                rp = (r - b) / (a - b) + ((r - b) % (a - b) != 0);

            if (a > l)
                lp = 1;
            if (a > r)
                rp = 1;

            // clog << '\t' << l << ' ' << r << ' ' << lp << ' ' << rp << '\n';
            if (lp >= rp)
                cout << lp << ' ';
            else
                cout << "-1 ";
        }
    }
    cout << '\n';
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