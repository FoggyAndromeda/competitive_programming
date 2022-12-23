#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> counter(1000, 0);
    for (int i = 0; i < n; ++i)
    {
        int now;
        cin >> now;
        ++counter[now];
    }
    int ans = 0;
    for (int i = 0; i < counter.size(); ++i)
    {
        ans += counter[i] >> 2;
    }
    cout << ans << '\n';
}