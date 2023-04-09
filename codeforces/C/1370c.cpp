#include <bits/stdc++.h>

using namespace std;

void first() { cout << "Ashishgup\n"; }
void second() { cout << "FastestFinger\n"; }

bool is_prime(int n)
{
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

void solve()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        second();
        return;
    }
    if (n == 2)
    {
        first();
        return;
    }
    if (n & 1)
    {
        first();
        return;
    }
    // Assuming n % 2^p == 0 (and n % 2^{p + 1} != 0):
    // if n == 2^p: second wins
    // if p > 1:
    //      first remove all odd dividers -> second substract 1 -> first wins
    // if p == 1:
    //      if n / 2 is prime: first is fucked up. second wins
    //      else first removes all odd dividers except one -> second removes odd divider (no more odd dividers left) -> first wins
    int p = 0;
    while (n % 2 == 0)
    {
        ++p;
        n >>= 1;
    }
    if (n == 1)
    {
        second();
        return;
    }
    if (p > 1)
    {
        first();
        return;
    }

    if (is_prime(n))
        second();
    else
        first();
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}