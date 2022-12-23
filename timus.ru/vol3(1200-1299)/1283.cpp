#include <bits/stdc++.h>

using namespace std;

int main()
{
    double n, l, k;
    cin >> n >> l >> k;
    k = 1 - k / 100.f;
    int i = 0;
    while (n > l)
    {
        n *= k;
        ++i;
    }
    cout << i << '\n';
}