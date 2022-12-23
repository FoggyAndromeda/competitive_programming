#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int counter = 0;
    bool ans = false;
    for (int i = 0; i < n; ++i)
    {
        int now;
        cin >> now;
        if (!((now >> 1) & 1))
            ans = !ans;
    }
    if (ans)
        cout << "Stannis\n";
    else
        cout << "Daenerys\n";
}