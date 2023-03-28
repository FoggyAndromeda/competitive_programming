#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> points;
    vector<int> times(n);
    points.reserve(2 * n);
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        points.push_back({a, a});
        points.push_back({b, a});
        times[i] = a;
    }
    sort(points.begin(), points.end());
    sort(times.begin(), times.end());
    int now = 0;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (points[i].second == times[now])
        {
            ++now;
            if (now < n)
                continue;
            cout << points[i].first << '\n';
            break;
        }
    }
}