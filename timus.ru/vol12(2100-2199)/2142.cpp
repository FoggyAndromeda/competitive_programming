#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    i64 a, b, c, x, y, z;
    cin >> a >> b >> c >> x >> y >> z;
    if (a < x)
    {
        c -= x - a;
        a += x - a;
    }
    if (b < y)
    {
        c -= y - b;
        b += y - b;
    }
    if (c < 0)
    {
        cout << "There are no miracles in life\n";
        return 0;
    }
    a -= x;
    b -= y;
    if ((a + b + c) >= z)
    {
        cout << "It is a kind of magic\n";
    }
    else
    {
        cout << "There are no miracles in life\n";
    }
}