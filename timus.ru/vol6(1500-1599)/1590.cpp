#pragma GCC optimize("Ofast,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

vector<int> prefix_f(string s)
{
    int n = s.size();
    vector<int> result(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = result[i - 1];
        while (j > 0 && s[j] != s[i])
            j = result[j - 1];
        if (s[j] == s[i])
            ++j;
        result[i] = j;
    }
    return result;
}

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        vector<int> pf = prefix_f(s.substr(n - i, i));
        ans += i - *max_element(pf.begin(), pf.end());
    }
    cout << ans << '\n';
}