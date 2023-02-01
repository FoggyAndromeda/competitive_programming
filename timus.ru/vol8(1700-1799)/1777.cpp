#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const i64 inf = 0x7fffffffffffffff;

int32_t main()
{
    i64 min_delta = inf;
    multiset<i64> heaps;
    for (int i = 0; i < 3; ++i)
    {
        i64 now;
        cin >> now;
        for (auto elem : heaps)
            min_delta = min(min_delta, abs(elem - now));
        heaps.insert(now);
    }
    i64 ans = 1;
    while (min_delta != 0)
    {
        ++ans;
        heaps.insert(min_delta);
        min_delta = inf;
        auto i = heaps.begin();
        i++;
        for (; i != heaps.end(); i++)
        {
            auto j = i;
            j--;
            min_delta = min(min_delta, abs(*j - *i));
        }
    }
    cout << ans << '\n';
}