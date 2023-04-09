#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, x0, y0;
    cin >> n >> x0 >> y0;
    set<pair<int, int>> ans;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        int dx = x - x0, dy = y - y0;
        if (dx == 0)
        {
            ans.insert({0, 1});
            continue;
        }
        if (dy == 0)
        {
            ans.insert({1, 0});
            continue;
        }
        int sgnx = dx / abs(dx), sgny = dy / abs(dy);
        if (sgnx * sgny == -1)
        {
            sgnx = -1;
            sgny = 1;
        }
        else
        {
            sgnx = 1;
            sgny = 1;
        }
        dx = abs(dx);
        dy = abs(dy);
        int g = __gcd(dx, dy);
        dx /= g;
        dy /= g;
        ans.insert({dx * sgnx, dy * sgny});
    }
    cout << ans.size() << '\n';
}