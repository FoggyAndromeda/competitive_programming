#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int a, b;
    cin >> a >> b;
    int d = __gcd(a, b);
    vector<int> factors;
    for (int i = 1; i * i <= d; ++i)
        if (d % i == 0)
        {
            factors.push_back(i);
            factors.push_back(d / i);
        }
    sort(factors.begin(), factors.end());
    factors.erase(unique(factors.begin(), factors.end()), factors.end());

    int n;
    cin >> n;
    while (n-- > 0)
    {
        int low, high;
        cin >> low >> high;

        int l = -1, r = factors.size();
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (factors[mid] <= high)
                l = mid;
            else
                r = mid;
        }

        if (factors[l] < low)
            cout << "-1\n";
        else
            cout << factors[l] << '\n';
    }
}