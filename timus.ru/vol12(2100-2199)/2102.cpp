#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

vector<i64> primes = []()
{
    int maxn = 1e7;
    vector<bool> is_prime(maxn, true);
    is_prime[0] = is_prime[1] = false;
    for (i64 i = 2; i * i < maxn; ++i)
        if (is_prime[i])
            for (i64 j = i * i; j < maxn; j += i)
                is_prime[j] = false;
    vector<i64> res;
    for (int i = 0; i < maxn; ++i)
        if (is_prime[i])
            res.push_back(i);
    return res;
}();

int result(i64 n)
{
    int ans = 0;
    for (i64 i : primes)
        while (n % i == 0)
        {
            ++ans;
            n /= i;
        }
    if (n != 1)
        ++ans;
    return ans;
}

int main()
{
    i64 n;
    cin >> n;
    if (result(n) == 20)
        cout << "YES\n";
    else
        cout << "NO\n";
}