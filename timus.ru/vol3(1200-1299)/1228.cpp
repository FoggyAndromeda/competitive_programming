#include <bits/stdc++.h>

using namespace std;

int main()
{
    int dims, s;
    cin >> dims >> s;
    --s;
    for (int i = 0; i < dims; ++i)
    {
        int now;
        cin >> now;
        cout << s / now << ' ';
        s %= now;
    }
}