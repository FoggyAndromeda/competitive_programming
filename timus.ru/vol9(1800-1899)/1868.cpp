#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    unordered_map<string, string> places;
    for (int i = 0; i < 4; ++i)
    {
        string s;
        cin >> s;
        places[s] = "gold";
    }
    for (int i = 0; i < 4; ++i)
    {
        string s;
        cin >> s;
        places[s] = "silver";
    }
    for (int i = 0; i < 4; ++i)
    {
        string s;
        cin >> s;
        places[s] = "bronze";
    }
    int n;
    cin >> n;
    vector<int> crp(n, 0);
    for (int i = 0; i < n; ++i)
    {
        int k;
        cin >> k;
        while (k-- > 0)
        {
            string s1, s2, s3;
            cin >> s1 >> s2 >> s3;
            crp[i] += (places[s1] == s3);
        }
    }
    sort(crp.begin(), crp.end());
    int ans = upper_bound(crp.begin(), crp.end(), crp[n - 1]) - lower_bound(crp.begin(), crp.end(), crp[n - 1]);
    cout << 5 * ans << '\n';
}