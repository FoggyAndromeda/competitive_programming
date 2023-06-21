#include <bits/stdc++.h>

using namespace std;

const int INF = 0x7fffffff;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a, b, ab;
    for (int i = 0; i < n; ++i)
    {
        int t, f, s;
        cin >> t >> f >> s;
        if (f == 0 && s == 0)
            continue;
        if (f == 1 && s == 1)
            ab.push_back(t);
        if (f == 0)
            b.push_back(t);
        if (s == 0)
            a.push_back(t);
    }
    a.push_back(0);
    b.push_back(0);
    ab.push_back(0);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    sort(ab.begin(), ab.end());
    for (int i = 1; i < a.size(); ++i)
        a[i] += a[i - 1];
    for (int i = 1; i < b.size(); ++i)
        b[i] += b[i - 1];
    for (int i = 1; i < ab.size(); ++i)
        ab[i] += ab[i - 1];

    int ans = INF;

    for (int i = min((int)ab.size() - 1, k); i > -1; --i)
    {
        // taking i books from ab
        // number of books from a and b k - i
        int abind = k - i;
        // clog << i << ' ' << abind << '\n';
        if (abind >= a.size() || abind >= b.size())
            break;
        ans = min(ans, ab[i] + a[abind] + b[abind]);
    }
    if (ans == INF)
        cout << "-1\n";
    else
        cout << ans << '\n';
}