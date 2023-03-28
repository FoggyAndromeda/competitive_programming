#include <bits/stdc++.h>

using namespace std;

int n, ans = 0;

void calculate(int len, int sum)
{
    if (sum > n)
        return;
    if (sum == n)
    {
        ++ans;
        return;
    }
    for (int i = len + 1; sum + i <= n; ++i)
        calculate(i, sum + i);
}

int main()
{
    cin >> n;
    calculate(0, 0);
    cout << ans << '\n';
}