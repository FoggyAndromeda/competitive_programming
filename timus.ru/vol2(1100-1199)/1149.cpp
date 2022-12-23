#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
        cout << '(';
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= i; ++j)
        {
            if (j > 1)
            {
                if (j & 1)
                    cout << '+';
                else
                    cout << '-';
            }
            cout << "sin(" << j;
        }
        for (int j = 1; j <= i; ++j)
            cout << ')';
        cout << '+' << n - i + 1;
        if (i < n)
            cout << ')';
    }
}