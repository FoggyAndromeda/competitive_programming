#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int a = 1;
    for (int i = 0; i < k - 1; ++i)
    {
        cout << a << ' ';
        a = -a;
        if (a > 0)
            ++a;
    }
    for (int i = k - 1; i < n; ++i)
        cout << "0 ";
}