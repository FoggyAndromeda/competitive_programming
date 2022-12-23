#include <bits\stdc++.h>

using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = 0;
    if (a & 1)
    {
        ans += 1;
        ++a;
    }
    if (b & 1)
    {
        ans += 1;
        --b;
    }
    ans += (b - a) >> 1;
    cout << ans;
}