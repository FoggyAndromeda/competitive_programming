#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int n = stoi(s);

    unordered_set<int> alibi;
    getline(cin, s);

    vector<vector<int>> successors(n + 1);
    vector<vector<int>> predecessors(n + 1);
    while (s != "BLOOD")
    {
        int a, b;
        a = stoi(s.substr(0, s.find(' ')));
        s = s.substr(s.find(' ') + 1);
        b = stoi(s);

        successors[b].push_back(a);
        predecessors[a].push_back(b);

        getline(cin, s);
    }

    function<void(int, bool)> dfs = [&](int v, bool up)
    {
        alibi.insert(v);
        if (up)
            for (int u : predecessors[v])
                dfs(u, true);
        else
            for (int u : successors[v])
                dfs(u, false);
    };

    while (getline(cin, s))
    {
        int a = stoi(s);
        dfs(a, true);
        dfs(a, false);
    };

    bool found = false;
    for (int i = 1; i <= n; ++i)
    {
        if (alibi.find(i) == alibi.end())
        {
            cout << i << ' ';
            found = true;
        }
    }
    if (!found)
        cout << 0;
    cout << '\n';
}