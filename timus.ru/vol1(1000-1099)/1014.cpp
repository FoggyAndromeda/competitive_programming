#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << "10\n";
        return 0;
    }
    if (n == 1)
    {
        cout << "1\n";
        return 0;
    }
    vector<int> simple_divisors;
    int now_div = 9;
    while (n > 1 && now_div > 1)
    {
        while (n % now_div == 0)
        {
            simple_divisors.push_back(now_div);
            n /= now_div;
        }
        --now_div;
    }
    if (now_div == 1 && n > 1)
        cout << -1 << '\n';
    else
    {
        sort(simple_divisors.begin(), simple_divisors.end());
        for (int elem : simple_divisors)
            cout << elem;
        cout << '\n';
    }
}