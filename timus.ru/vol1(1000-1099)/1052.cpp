#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<int, int>> points(n);
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        points[i] = {x, y};
    }
    int ans = 0;
    for (int i = 0; i < n; ++i)
    {
        int x0 = points[i].first, y0 = points[i].second;
        for (int j = 0; j < i; ++j)
        {
            int now_dx = x0 - points[j].first, now_dy = y0 - points[j].second;
            int now_points = 0;
            if (now_dx != 0 && now_dy != 0)
            {
                int gcd_ = gcd(now_dx, now_dy);
                now_dx /= gcd_;
                now_dy /= gcd_;
                for (int k = 0; k < n; ++k)
                {
                    int x = points[k].first, y = points[k].second;
                    int delta_x = x - x0, delta_y = y - y0;
                    if (delta_x % now_dx == 0 && delta_y % now_dy == 0 && delta_x / now_dx == delta_y / now_dy)
                    {
                        ++now_points;
                    }
                }
            }
            else if (now_dx == 0)
            {
                for (int k = 0; k < n; ++k)
                {
                    int x = points[k].first, y = points[k].second;
                    if (x == x0)
                        ++now_points;
                }
            }
            else if (now_dy == 0)
            {
                for (int k = 0; k < n; ++k)
                {
                    int x = points[k].first, y = points[k].second;
                    if (y == y0)
                        ++now_points;
                }
            }
            ans = max(now_points, ans);
        }
    }
    cout << ans << '\n';
}