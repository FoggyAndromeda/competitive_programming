#include <bits\stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    i64 n;
    cin >> n;
    vector<i64> lens(n);
    i64 weight = 0;
    for (i64 i = 0; i < n; ++i)
    {
        cin >> lens[i];
        weight += lens[i];
    }
    sort(lens.begin(), lens.end());
    i64 ans = 0;
    for (i64 i = 0; i < n; ++i)
    {
        ans += weight * lens[i];
        weight -= lens[i];
        ans += weight * lens[i];
    }
    cout << ans << '\n';
}