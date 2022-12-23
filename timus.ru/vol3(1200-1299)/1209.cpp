#include <bits\stdc++.h>

using namespace std;

using ui64 = uint64_t;

bool is_square(ui64 a)
{
    ui64 l = 0, r = a;
    while (r - l > 1)
    {
        ui64 mid = (l + r) >> 1;
        if (mid * mid > a)
            r = mid;
        else
            l = mid;
    }
    return (l * l == a || r * r == a);
}

int main()
{
    int n;
    cin >> n;
    while (n-- > 0)
    {
        ui64 now;
        cin >> now;
        --now;
        if (is_square(1 + (now << 3)))
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }
    cout << '\n';
}