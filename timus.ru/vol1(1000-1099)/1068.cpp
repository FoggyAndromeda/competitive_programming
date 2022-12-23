#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n < 1)
    {
        cout << (n + 1) * (2 - n) / 2 << '\n';
    }
    else if (n == 1)
    {
        cout << 1 << '\n';
    }
    else
    {
        cout << (n + 1) * n / 2 << '\n';
    }
}