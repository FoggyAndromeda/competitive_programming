#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<i64> pref(n);
    cin >> pref[0];
    for (int i = 1; i < n; ++i)
    {
        i64 now;
        cin >> now;
        pref[i] = pref[i - 1] + now;
    }
    if (pref[n - 1] % 3 != 0)
    {
        cout << "0\n";
        return 0;
    }
    i64 sumthird = pref[n - 1] / 3;

    list<i64> okpref;
    for (int i = 0; i < n; ++i)
        if (pref[i] == sumthird)
            okpref.push_back(i);

    list<i64> oksuff;
    for (int i = n - 1; i > 0; --i)
        if (pref[n - 1] - pref[i - 1] == sumthird)
            oksuff.push_back(i);
    if (pref[n - 1] == sumthird)
        oksuff.push_back(0);
    reverse(oksuff.begin(), oksuff.end());

    i64 ans = 0;
    list<i64>::iterator i = okpref.begin(), j = oksuff.begin();
    i64 k = 0;
    while (i != okpref.end() && j != oksuff.end())
    {
        if ((*j) - (*i) > 1)
        {
            ans += oksuff.size() - k;
            i++;
        }
        else
        {
            j++;
            k++;
        }
    }
    cout << ans << '\n';
}