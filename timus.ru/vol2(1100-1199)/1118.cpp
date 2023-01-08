#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const int maxn = 1e6 + 10;
vector<int> primes = []()
{
    vector<bool> prime(maxn, true);
    prime[0] = false;
    prime[1] = false;
    for (i64 i = 2; i < maxn; ++i)
        if (prime[i])
            for (i64 j = i * i; j < maxn; j += i)
                prime[j] = false;
    vector<int> res;
    for (int i = 0; i < maxn; ++i)
        if (prime[i])
            res.push_back(i);
    return res;
}();

double triv(int n)
{
    static unordered_map<int, double> res;
    if (n == 1)
        return 0;
    if (res.find(n) != res.end())
        return res[n];
    double num = 1;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0)
        {
            num += i;
            if (i * i != n)
                num += n / i;
        }
    res[num] = num / double(n);
    return num / double(n);
}

int main()
{
    int l, r;
    cin >> l >> r;
    if (l == 1)
    {
        cout << "1\n";
        return 0;
    }
    if (r > 2)
    {
        int bsl = 0, bsr = primes.size() - 1;
        while (bsr - bsl > 1)
        {
            int bsm = (bsr + bsl) >> 1;
            if (primes[bsm] > r)
                bsr = bsm;
            else
                bsl = bsm;
        }
        if (primes[bsl] > l)
        {
            cout << primes[bsl] << '\n';
            return 0;
        }
    }
    int min_triv = l;
    for (int i = l + 1; i <= r; ++i)
    {
        if (triv(i) < triv(min_triv))
            min_triv = i;
    }
    cout << min_triv << '\n';
}