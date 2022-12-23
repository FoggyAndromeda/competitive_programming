#include <bits/stdc++.h>

using namespace std;

const int maxlen = 1'000'000;

int main()
{
    vector<int> a = {0, 0, 0, 0};
    int len = 0;
    while (len < maxlen)
    {
        for (int i = 1; i < 4; ++i)
        {
            putchar('a' + a[i]);
            ++len;
            if (len == maxlen)
                break;
        }
        ++a[3];
        for (int i = 2; i > 0; --i)
            a[i] += a[i + 1] / 26;
        for (int i = 0; i < 4; ++i)
            a[i] %= 26;
    }
}