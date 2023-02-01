#include <bits/stdc++.h>

using namespace std;

const int begin_code = -1;
const int end_code = 1e5 + 2;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> points;
    for (int i = 0; i < n; ++i)
    {
        int b, e;
        cin >> b >> e;
        points.push_back({b, begin_code});
        points.push_back({e, end_code});
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int now;
        cin >> now;
        points.push_back({now, i});
    }
    vector<int> ans(m);
    sort(points.begin(), points.end());

    int now_segment = 1;
    stack<int> segments;
    for (auto [p, code] : points)
    {
        if (code == begin_code)
        {
            segments.push(now_segment);
            ++now_segment;
            continue;
        }
        if (code == end_code)
        {
            segments.pop();
            continue;
        }
        if (segments.empty())
            ans[code] = -1;
        else
            ans[code] = segments.top();
    }
    for (auto a : ans)
        cout << a << '\n';
}