#include <bits\stdc++.h>

using namespace std;

using i64 = int64_t;

int main()
{
    i64 n;
    string s;
    cin >> n >> s;
    i64 res = 1;
    while (n > 0)
    {
        res *= n;
        n -= s.size();
    }
    cout << res << '\n';
}