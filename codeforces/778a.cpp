#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string t, p;
    cin >> t >> p;
    int n = t.size();

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        int now;
        cin >> now;
        --now;
        a[now] = i;
    }
    int l = -1, r = n;
    while (r - l > 1)
    {
        int m = (l + r) >> 1;

        int i = 0;
        for (int j = 0; j < n && i < p.size(); ++j)
        {
            if (a[j] <= m)
                continue;
            if (t[j] == p[i])
                ++i;
        }

        if (i == p.size())
            l = m;
        else
            r = m;
    }
    cout << l + 1 << '\n';
}