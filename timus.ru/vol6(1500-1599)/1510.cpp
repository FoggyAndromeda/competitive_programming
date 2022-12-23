#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> count;
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        ++count[a];
    }
    int ans = 0;
    for (auto [i, c] : count)
    {
        if (c > count[ans])
            ans = i;
    }
    cout << ans << '\n';
}