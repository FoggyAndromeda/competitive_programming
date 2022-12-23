#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> prefs(n + 1);
    for (int i = 1; i <= n; ++i)
    {
        int now;
        cin >> now;
        prefs[i] = prefs[i - 1] + now;
    }
    int q;
    cin >> q;
    while (q-- > 0)
    {
        int l, r;
        cin >> l >> r;
        cout << prefs[r] - prefs[l - 1] << '\n';
    }
}