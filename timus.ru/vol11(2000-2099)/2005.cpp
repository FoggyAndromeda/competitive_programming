#include <bits\stdc++.h>

using namespace std;

const int n = 5;
const int infi = 1e9;

int main()
{
    vector<vector<int>> dist(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> dist[i][j];
        }
    }
    int ans = infi;
    vector<int> path;

    for (int a = 1; a < 4; ++a)
    {
        for (int b = 1; b < 4; ++b)
        {
            for (int c = 1; c < 4; ++c)
            {
                if (a == b || b == c || a == c || c == 2)
                    continue;
                int d = dist[0][a] + dist[a][b] + dist[b][c] + dist[c][4];
                if (d < ans)
                {
                    ans = d;
                    path = {0, a, b, c, 4};
                }
            }
        }
    }

    cout << ans << '\n';
    for (int i = 0; i < n; ++i)
    {
        cout << path[i] + 1 << ' ';
    }
}