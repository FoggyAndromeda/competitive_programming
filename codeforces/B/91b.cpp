#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end());
    vector<int> result(n);
    result[a[0].second] = -1;
    int max_index = -1;
    for (int i = 1; i < n; ++i)
    {
        if (a[i].first != a[i - 1].first)
            max_index = max(max_index, a[i - 1].second);
        result[a[i].second] = max(max_index - a[i].second - 1, -1);
    }
    for (auto elem : result)
        cout << elem << ' ';
    cout << '\n';
}
