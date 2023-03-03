#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        char c;
        cin >> c;
        a[i] = (c == '>');
    }
    int cnt1 = 0, ans = 0;
    for (int i = n - 1; i > -1; --i)
    {
        if (a[i] == 1)
        {
            // clog << "Position " << i << " Now " << cnt1 << " ones " << (n - cnt1 - 1) - i << " more moves\n";
            ans += (n - cnt1 - 1) - i;
            ++cnt1;
        }
    }
    cout << ans << endl;
}