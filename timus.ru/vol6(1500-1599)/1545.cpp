#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> v(30);
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        v[s[0] - 'a'].push_back(s);
    }
    char c;
    cin >> c;
    for (string s : v[c - 'a'])
    {
        cout << s << '\n';
    }
}