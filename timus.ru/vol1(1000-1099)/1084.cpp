#include <bits\stdc++.h>

using namespace std;

const double pi = 3.141592653589793238462643383279502884197169399375;

const double quater_pi = pi / 4.f;

int main()
{
    double farm_side, rope_len;
    cin >> farm_side >> rope_len;
    farm_side /= 2.0;
    double l = 0.f, r = quater_pi;
    while (r - l > 0.0000000001)
    {
        double mid = (l + r) / 2.f;
        if (rope_len * cos(mid) > farm_side)
            l = mid;
        else
            r = mid;
    }
    double angle = l;
    double triangle = farm_side * farm_side * tanl(angle);
    double circle = rope_len * rope_len * (quater_pi - angle);
    printf("%.3f\n", 4.f * (triangle + circle));
}