#include <bits/stdc++.h>

using namespace std;
using ld = long double;

const ld PI = 3.1415926535;
const ld g = 10;

int main()
{
    cout << fixed << setprecision(2);
    ld v, a, k;
    cin >> v >> a >> k;
    a = a * PI / 180.f;
    ld ans = 0;
    ld energy = v * v / 2.f;
    while (energy > 1e-4)
    {
        ld now_v = sqrtl(2 * energy);
        ld t = 2 * now_v * sinl(a) / g;
        ans += now_v * cosl(a) * t;
        energy /= k;
    }
    cout << ans << '\n';
}