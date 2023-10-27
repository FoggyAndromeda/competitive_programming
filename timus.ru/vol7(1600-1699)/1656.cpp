#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n * n);
    for (int i = 0; i < n * n; ++i)
        cin >> a[i];
    sort(a.begin(), a.end());
    vector<vector<int>> result(n, vector<int>(n, -1));
    deque<pair<int, int>> d;
    d.emplace_back(n / 2, n / 2);
    int ind = n * n - 1;
    while (!d.empty())
    {
        auto [i, j] = d.front();
        d.pop_front();
        if (i < 0 || i >= n)
            continue;
        if (j < 0 || j >= n)
            continue;
        if (result[i][j] != -1)
            continue;
        result[i][j] = a[ind--];
        d.emplace_back(i - 1, j);
        d.emplace_back(i + 1, j);
        d.emplace_back(i, j - 1);
        d.emplace_back(i, j + 1);
    }
    for (auto &line : result)
    {
        for (auto elem : line)
            cout << elem << ' ';
        cout << '\n';
    }
}