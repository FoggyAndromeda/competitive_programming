#include <bits/stdc++.h>

using namespace std;

bool is_prime(int n)
{
    if (n == 2)
        return true;
    if (n % 2 == 0)
        return false;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
            return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<int> ans;
    for (int i = 2; i <= n; ++i)
    {
        if (!is_prime(i))
            continue;
        int j = i;
        while (j <= n)
        {
            ans.push_back(j);
            j *= i;
        }
    }
    cout << ans.size() << '\n';
    for (auto elem : ans)
        cout << elem << ' ';
    cout << '\n';
}