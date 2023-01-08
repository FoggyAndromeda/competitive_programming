#include <bits/stdc++.h>

using namespace std;

int main()
{
    int b, r, y;
    cin >> b >> r >> y;
    int k;
    cin >> k;
    int ans = 1;
    for (int i = 0; i < k; ++i)
    {
        string s;
        cin >> s;
        if (s == "Blue")
            ans *= b;
        else if (s == "Yellow")
            ans *= y;
        else
            ans *= r;
    }
    cout << ans << '\n';
}