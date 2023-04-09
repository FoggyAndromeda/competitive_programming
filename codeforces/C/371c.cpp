#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string st;
    cin >> st;
    vector<i64> need(3);
    for (i64 i = 0; i < st.size(); ++i)
    {
        need[0] += st[i] == 'B';
        need[1] += st[i] == 'S';
        need[2] += st[i] == 'C';
    }
    vector<i64> count(3);
    for (int i = 0; i < 3; ++i)
        cin >> count[i];
    vector<i64> prices(3);
    for (int i = 0; i < 3; ++i)
        cin >> prices[i];
    i64 money;
    cin >> money;
    i64 l = 0, r = 1'000'000'000'000'000;
    while (r - l > 1)
    {
        i64 m = (l + r) >> 1;
        i64 need_money = 0;
        for (int i = 0; i < 3; ++i)
            need_money += max(need[i] * m - count[i], 0ll) * prices[i];

        if (need_money <= money)
            l = m;
        else
            r = m;
    }
    cout << l << '\n';
}