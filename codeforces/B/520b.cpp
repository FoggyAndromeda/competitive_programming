#include <bits/stdc++.h>

using namespace std;
const int INF = 0x7fffffff;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> dist(30'000, INF);
    stack<pair<int, int>> s;
    s.push({n, 0});
    while (!s.empty())
    {
        auto [i, cnt] = s.top();
        s.pop();
        if (i < 0 || i >= dist.size())
            continue;
        if (dist[i] <= cnt)
            continue;
        dist[i] = cnt;
        s.push({2 * i, cnt + 1});
        s.push({i - 1, cnt + 1});
    }
    cout << dist[m] << '\n';
}