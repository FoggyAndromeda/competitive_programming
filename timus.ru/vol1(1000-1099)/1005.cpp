#include <bits\stdc++.h>

using namespace std;

const int INFI = 1e9;

int main()
{
    int n;
    cin >> n;
    vector<int> weights(n);
    for (int i = 0; i < n; ++i)
        cin >> weights[i];
    int ans = INFI;
    for (int i = 0; i < 1 << n; ++i)
    {
        int a = 0, b = 0;
        for (int j = 0; j < n; ++j)
        {
            if ((i >> j) & 1)
                a += weights[j];
            else
                b += weights[j];
        }
        ans = min(ans, abs(a - b));
    }
    cout << ans << '\n';
}