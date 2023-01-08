#include <bits/stdc++.h>

using namespace std;

bool is_upper(const char c)
{
    return ('A' <= c && c <= 'Z');
}

bool is_lower(const char c)
{
    return ('a' <= c && c <= 'z');
}

char to_lower(const char c)
{
    if (is_upper(c))
        return 'a' + c - 'A';
    return c;
}

int main()
{
    string name = "Sandro";
    string s;
    cin >> s;
    int ans = 0x7fffffff;
    for (int i = 0; i + name.size() <= s.size(); ++i)
    {
        int now = 0;
        for (int j = 0; j < name.size(); ++j)
        {
            if (to_lower(s[i + j]) != to_lower(name[j]))
                now += 5;
            if (is_lower(s[i + j]) && is_upper(name[j]))
                now += 5;
            if (is_upper(s[i + j]) && is_lower(name[j]))
                now += 5;
        }
        ans = min(ans, now);
    }
    cout << ans << '\n';
}