#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (n == 1 || s[0] <= s[1])
        {
            cout << s[0] << s[0] << '\n';
            continue;
        }
        string ans;
        for (int i = 0; i < n; ++i)
        {
            ans.push_back(s[i]);
            if (i + 1 < n && s[i] < s[i + 1])
                break;
        }
        cout << ans;
        reverse(ans.begin(), ans.end());
        cout << ans;
        cout << '\n';
    }
}