#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> edges(n);
    for (int i = 1; i < n; ++i)
    {
        int pr;
        cin >> pr;
        --pr;
        edges[i].push_back(pr);
        edges[pr].push_back(i);
    }
    vector<int> lvl(n, 0);
    vector<int> degree(n);
    queue<int> q;
    for (int i = 0; i < n; ++i)
    {
        degree[i] = edges[i].size();
        if (degree[i] == 1)
            q.push(i);
    }
    while (!q.empty())
    {
        int v = q.front();
        q.pop();

        for (auto nxt : edges[v])
        {
            --degree[nxt];
            if (degree[nxt] == 1)
            {
                q.push(nxt);
                lvl[nxt] = lvl[v] + 1;
            }
        }
    }
    int maxlvl = *max_element(lvl.begin(), lvl.end());
    for (int i = 0; i < n; ++i)
    {
        if (lvl[i] == maxlvl)
            cout << i + 1 << ' ';
    }
    cout << '\n';
}
