#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    map<string, vector<string>> d;
    map<string, int> dist;
    set<string> names;
    for (int i = 0; i < n; ++i)
    {
        string a, b, c;
        cin >> a >> b >> c;
        names.insert(a);
        names.insert(b);
        names.insert(c);
        dist[a] = dist[b] = dist[c] = -1;
        d[a].push_back(b);
        d[a].push_back(c);
        d[b].push_back(a);
        d[b].push_back(c);
        d[c].push_back(a);
        d[c].push_back(b);
    }

    queue<pair<string, int>> q;
    q.push({"Isenbaev", 0});

    while (!q.empty())
    {
        auto [name, now_dist] = q.front();
        q.pop();
        if (dist[name] != -1 && dist[name] <= now_dist)
            continue;
        dist[name] = now_dist;
        for (string nxt : d[name])
        {
            q.push({nxt, now_dist + 1});
        }
    }

    for (auto now_name : names)
    {
        if (dist[now_name] == -1)
            cout << now_name << ' ' << "undefined" << '\n';
        else
            cout << now_name << ' ' << dist[now_name] << '\n';
    }
}