#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    vector<list<int>> prev(n);
    for (int i = 0; i < m; ++i)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        prev[r].push_back(l);
    }

    unordered_set<int> visited;
    bool ans = true;
    for (int i = 0; i < n; ++i)
    {
        int now;
        cin >> now;
        --now;
        for (int pr : prev[now])
            if (visited.find(pr) == visited.end())
                ans = false;
        visited.insert(now);
    }
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
    cout.flush();
}