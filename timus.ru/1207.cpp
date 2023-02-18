#include <bits/stdc++.h>

using namespace std;

struct pnt
{
    int64_t x, y;
};

int main()
{
    int n;
    cin >> n;

    vector<pnt> points(n);

    int leftest = 0;
    cin >> points[0].x >> points[0].y;

    for (int i = 1; i < n; ++i)
    {
        cin >> points[i].x >> points[i].y;
        if (points[i].x < points[leftest].x)
            leftest = i;
    }

    vector<pair<double, int>> angles;
    angles.reserve(n - 1);
    for (int i = 0; i < n; ++i)
    {
        if (i == leftest)
            continue;
        angles.push_back({atan2(double(points[i].y - points[leftest].y),
                                double(points[i].x - points[leftest].x)),
                          i});
    }
    sort(angles.begin(), angles.end());

    cout << leftest + 1 << ' ' << angles[(n - 1) / 2].second + 1 << '\n';
}