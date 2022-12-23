#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> res(n + 1);
    for (int i = 1; i < n + 1; ++i)
    {
        int a, b;
        cin >> a >> b;
        res[i] = a + b;
    }
    for (int i = n; i > 0; --i)
    {
        res[i - 1] += res[i] / 10;
        res[i] %= 10;
    }
    for (int i = 1; i < n + 1; ++i)
        cout << res[i];
    cout << '\n';
}