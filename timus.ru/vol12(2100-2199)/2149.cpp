#include <bits/stdc++.h>

using namespace std;

vector<string> perfect;

void generate_perfect(int n)
{
    perfect.reserve(4);
    {
        string s(n, '<');
        for (int i = n / 2; i < n; ++i)
            s[i] = '>';
        perfect.push_back(s);
    }
    {
        string s(n, '>');
        for (int i = n / 2; i < n; ++i)
            s[i] = '<';
        perfect.push_back(s);
    }
    {
        string s(n, '<');
        for (int i = 0; i < n; i += 2)
            s[i] = '>';
        perfect.push_back(s);
    }
    {
        string s(n, '>');
        for (int i = 0; i < n; i += 2)
            s[i] = '<';
        perfect.push_back(s);
    }
}

int main()
{
    int n;
    cin >> n;
    generate_perfect(n);
    string s;
    cin >> s;
    string directions;
    directions.reserve(n);
    for (char c : s)
        if (c == '<' || c == '>')
            directions.push_back(c);
    cin >> s;
    cin >> s;
    int ans = 0x7fffffff;
    for (string &perm : perfect)
    {
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (perm[i] != directions[i])
                ++cnt;
        ans = min(ans, cnt);
    }
    cout << ans << '\n';
}