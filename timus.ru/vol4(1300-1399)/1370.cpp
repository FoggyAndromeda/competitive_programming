#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    m %= n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < 10; ++i)
    {
        cout << a[(m + i) % n];
    }
    cout << '\n';
}