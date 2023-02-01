#include <bits/stdc++.h>

using namespace std;

int main()
{
    int f, m;
    cin >> f >> m;
    vector<int> girls(f), boys(m);
    for (int &i : girls)
        cin >> i;
    for (int &i : boys)
        cin >> i;
    sort(girls.begin(), girls.end(), greater<int>());
    sort(boys.begin(), boys.end(), greater<int>());
    for (int i = 1; i < f; ++i)
        girls[i] += girls[i - 1];
    for (int i = 1; i < m; ++i)
        boys[i] += boys[i - 1];
    int ans = girls[f - 1];
    for (int i = 1; i <= min(f, m); ++i)
        ans = min(ans, girls[f - 1] - girls[i - 1] + (boys[m - 1] - boys[i - 1]) * i);
    cout << ans << '\n';
}