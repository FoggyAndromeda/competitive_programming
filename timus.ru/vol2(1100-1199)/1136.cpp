#include <bits/stdc++.h>

using namespace std;
vector<int> a;

void calc(int l, int r)
{
    if (l > r)
        return;
    if (r > l)
    {
        int first_less = -1;
        for (int i = r - 1; i >= l; --i)
            if (a[i] < a[r])
            {
                first_less = i;
                break;
            }
        if (first_less == -1)
            calc(l, r - 1);
        else
        {
            calc(first_less + 1, r - 1);
            calc(l, first_less);
        }
    }
    cout << a[r] << '\n';
};

int main()
{
    int n;
    cin >> n;
    a.assign(n, 0);
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    calc(0, n - 1);
}