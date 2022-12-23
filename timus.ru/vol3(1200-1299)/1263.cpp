#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1, 0);
    for (int i = 0; i < m; ++i)
    {
        int now;
        cin >> now;
        ++a[now];
    }
    for (int i = 1; i <= n; ++i)
    {
        printf("%.2f%\n", 100 * double(a[i]) / double(m));
    }
}