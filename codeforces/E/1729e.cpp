#include <bits/stdc++.h>

using namespace std;

#define int int64_t

void ask(int a, int b)
{
    cout << "? " << a << ' ' << b << endl;
}

void ans(int a)
{
    cout << "! " << a << endl;
}

int32_t main()
{
    for (int i = 2; i < 25; ++i)
    {
        int ltb, btl;
        ask(1, i);
        cin >> ltb;
        if (ltb == -1)
        {
            ans(i - 1);
            break;
        }
        ask(i, 1);
        cin >> btl;
        if (btl == ltb)
            continue;
        ans(btl + ltb);
        break;
    }
    ans(-1);
}