#include <bits/stdc++.h>

using namespace std;

const string s = ".00000 ";

int main()
{
    int l, k, t;
    cin >> l >> k >> t;
    if (l % k == 0)
        cout << l / k * t << s << l / k * t << s;
    else
        cout << l / k * t << s << (l / k + 1) * t << s;
}