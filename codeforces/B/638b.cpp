#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> ins(n);
    set<char> firsts;
    for (int i = 0; i < n; ++i)
    {
        cin >> ins[i];
        firsts.insert(ins[i][0]);
    }
    for (int i = 0; i < n; ++i)
        for (int j = 1; j < ins[i].size(); ++j)
            firsts.erase(ins[i][j]);
    map<char, char> after;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < ins[i].size() - 1; ++j)
            after[ins[i][j]] = ins[i][j + 1];
    for (char f : firsts)
    {
        char now = f;
        while (1)
        {
            cout << now;
            if (after.find(now) == after.end())
                break;
            now = after[now];
        }
    }
    cout << '\n';
}