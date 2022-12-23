#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    int l = k, r = 0;
    for (int i = 0; i < n; ++i)
    {
        int a, b;
        cin >> a >> b;
        l += a;
        r += b;
    }
    int waited = l - 2 * (n + 1);
    int result = waited - r;
    if (result < 0)
        cout << "Big Bang!\n";
    else
        cout << result << '\n';
}