#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> result = {0};
    for (int i = 1; i * i <= n; ++i)
    {
        result.push_back(i);
        result.push_back(n / i);
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    cout << result.size() << '\n';
    for (auto elem : result)
        cout << elem << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}