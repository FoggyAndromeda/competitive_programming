#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> data(n);
    for (int i = 0; i < n; ++i)
        cin >> data[i].first >> data[i].second;
    stable_sort(data.begin(), data.end(), [](pair<int, int> f, pair<int, int> s)
                { return f.second > s.second; });
    for (auto elem : data)
    {
        cout << elem.first << ' ' << elem.second << '\n';
    }
}