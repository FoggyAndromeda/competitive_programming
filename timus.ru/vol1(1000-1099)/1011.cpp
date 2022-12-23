#include <bits\stdc++.h>

using namespace std;

int main()
{
    double l_per, r_per;
    cin >> l_per >> r_per;
    l_per += 0.0000000001;
    r_per -= 0.0000000001;
    l_per /= 100.f;
    r_per /= 100.f;
    for (double i = 0; i < 10000; ++i)
    {
        // clog << floor(i * l_per) - floor(i * r_per) << '\n';
        if (floor(i * l_per) < floor(i * r_per))
        {
            cout << int(i) << '\n';
            return 0;
        }
    }
}