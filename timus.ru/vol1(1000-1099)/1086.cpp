#include <bits\stdc++.h>

using namespace std;

bool is_prime(int x)
{
    if (x % 2 == 0 || x == 1)
        return false;
    for (int i = 3; i * i <= x; i += 2)
    {
        if (x % i == 0)
            return false;
    }
    return true;
}

const vector<int> primes = []()
{
    vector<int> result;
    result.push_back(2);
    int now = 3;
    while (result.size() < 15000)
    {
        if (is_prime(now))
            result.push_back(now);
        now += 2;
    }
    return result;
}();

int main()
{
    int n;
    cin >> n;
    while (n-- > 0)
    {
        int a;
        cin >> a;
        --a;
        cout << primes[a] << '\n';
    }
}