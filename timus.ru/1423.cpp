#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

vector<int> prefixf(string &s)
{
    int n = s.size();
    vector<int> res(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = res[i - 1];
        while (j > 0 && s[i] != s[j])
            j = res[j - 1];
        if (s[i] == s[j])
            ++j;
        res[i] = j;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    s = s + " " + t + t;
    vector<int> pf = prefixf(s);
    int ans = -1;
    for (int i = 0; i <= n; ++i)
    {
        if (pf[3 * n - i] == n)
            ans = n - i;
    }
    cout << ans << '\n';
}