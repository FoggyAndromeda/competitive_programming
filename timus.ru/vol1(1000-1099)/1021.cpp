#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> need;
    while (n-- > 0)
    {
        int a;
        cin >> a;
        need.insert(10000 - a);
    }
    cin >> n;
    bool ans = false;
    while (n-- > 0)
    {
        int a;
        cin >> a;
        if (need.find(a) != need.end())
            ans = true;
    }
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
}