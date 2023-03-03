#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    int f, s;
    cin >> f >> s;
    --f;
    --s;
    if (f > s)
    {
        reverse(a.begin(), a.end());
        f = n - f - 1;
        s = n - s - 1;
    }
    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; ++i)
        pref[i] = pref[i - 1] + a[i];
    auto rq = [&](int l, int r)
    {
        if (l == 0)
            return pref[r];
        return pref[r] - pref[l - 1];
    };
    int ansf;
    if (f == s)
        ansf = max(rq(0, f), rq(f, n - 1));
    else
        ansf = rq(0, f + (s - f + 1) / 2 + (s - f + 1) % 2 - 1);
    cout << ansf << ' ' << rq(0, n - 1) - ansf << '\n';
}