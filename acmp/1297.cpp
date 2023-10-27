#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n)
{
    if (n == 0 || n == 1)
        return false;
    if (n == 2)
        return true;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int l, r;
    cin >> l >> r;
    bool found = false;
    for (int i = l; i <= r; ++i)
        if (is_prime(i))
        {
            found = true;
            cout << i << '\n';
        }
    if (!found)
        cout << "Absent\n";
}