#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    i64 price, num;
    cin >> price >> num;
    price = 3 * price;
    i64 alone = 0, ans = -1;
    for (i64 i = 0; i < num; ++i)
    {
        i64 now;
        cin >> now;
        alone += now;
        if (alone > price && ans == -1)
            ans = i + 1;
    }
    if (ans != -1)
        cout << "Free after " << ans << " times.\n";
    else
        cout << "Team.GOV!\n";
}