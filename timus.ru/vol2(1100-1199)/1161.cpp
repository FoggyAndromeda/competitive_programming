#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<double> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = n - 2; i > -1; --i)
    {
        a[i] = 2 * sqrtl(a[i + 1] * a[i]);
    }
    cout << fixed << showpoint;
    cout << setprecision(2);
    cout << a[0] << '\n';
}