#include <bits/stdc++.h>

using namespace std;

bool is_letter(char c)
{
    return (('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z'));
}

int main()
{
    string s;
    while (getline(cin, s))
    {
        int l, r;
        l = r = 0;
        while (l < s.size())
        {
            while (!is_letter(s[l]))
                ++l;
            r = l;
            while (r < s.size() && is_letter(s[r]))
                ++r;
            --r;
            reverse(s.begin() + l, s.begin() + r);
            l = r;
        }
        cout << s << '\n';
    }
}