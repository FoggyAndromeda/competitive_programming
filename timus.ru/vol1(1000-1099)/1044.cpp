#include <bits\stdc++.h>

using namespace std;

int binpow(int a, int b)
{
    int res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res *= a;
            --b;
        }
        a *= a;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> count_sums(9 * n / 2 + 1);
    for (int i = 0; i < binpow(10, n / 2); ++i)
    {
        int now_sum = 0, k = i;
        while (k != 0)
        {
            now_sum += k % 10;
            k /= 10;
        }
        ++count_sums[now_sum];
    }
    int res = 0;
    for (int elem : count_sums)
        res += elem * elem;
    cout << res << '\n';
}