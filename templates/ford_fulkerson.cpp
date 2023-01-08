#include <bits/stdc++.h>

using namespace std;

//! CHECKED?

int ford_fulkerson(vector<vector<int>> &c)
{
    const int INFI = 1e9;
    const int n = c.size();

    vector<vector<int>> flows(n, vector<int>(n, 0)); // потоки, проходяшие по ребрам
    while (true)
    {
        vector<int> prev(n, -1); // вершины, из которых мы пришли в данную
        stack<int> q;
        q.push(0);
        prev[0] = 0;
        while (!q.empty())
        {
            int current = q.top();
            q.pop();
            for (int v = 0; v < n; ++v)
                if (prev[v] == -1 && c[current][v] - flows[current][v] > 0)
                {
                    q.push(v);
                    prev[v] = current;
                }
        }

        if (prev[n - 1] == -1)
            break;

        int current_flow = INFI;
        for (int current = n - 1; current != 0; current = prev[current])
        {
            int p = prev[current];
            current_flow = min(current_flow, c[p][current] - flows[p][current]);
        }

        for (int current = n - 1; current != 0; current = prev[current])
        {
            int p = prev[current];
            flows[p][current] += current_flow;
            flows[current][p] -= current_flow;
        }
    }
    int result = 0;
    for (int i = 0; i < n; ++i)
        if (c[0][i] != 0)
            result += flows[0][i];
    return result;
}

int main()
{
}