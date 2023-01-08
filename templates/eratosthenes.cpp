#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const int maxn = 1e6 + 1;
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

int main()
{
}