#include <bits\stdc++.h>

using namespace std;

using ui64 = uint64_t;

int main()
{
    ui64 n, m;
    cin >> n >> m;
    cout << min(2 * (n - 1), 2 * m - 1);
}