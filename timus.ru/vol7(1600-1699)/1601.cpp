#include <bits\stdc++.h>

using namespace std;

int main()
{
    char c;
    bool is_begin = true;
    while (cin >> c)
    {
        if (c == '!' || c == '?' || c == '.')
            is_begin = true;
        if (!is_begin && c >= 'A' && c <= 'Z')
        {
            c = 'a' + c - 'A';
        }
        if (is_begin && c >= 'A' && c <= 'Z')
            is_begin = false;
        cout << c;
    }
}