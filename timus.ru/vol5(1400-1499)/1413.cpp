#include <bits/stdc++.h>

using namespace std;
using ld = long double;

const ld pi = 3.1415926535897932384626433832795;

const vector<ld> angles = {1, -0.75 * pi, -0.5 * pi, -0.25 * pi, pi, 1, 0, 0.75 * pi, 0.5 * pi, 0.25 * pi};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    cout << fixed << setprecision(10);
    char c;
    ld x = 0, y = 0;
    while (cin >> c)
    {
        if (c == '0')
            break;
        if (c == '5')
            continue;
        x += cosl(angles[c - '0']);
        y += sinl(angles[c - '0']);
    }
    cout << x << ' ' << y << '\n';
}