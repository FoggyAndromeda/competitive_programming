#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;

int N = 7;
int M = 7;

inline bool check(int r, int c, vector<vector<int>> &mp)
{
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (mp[i][j] == mp[r][c] && mp[r][j] == mp[i][c] && mp[i][j] == mp[i][c])
                return false;
    return true;
}

void calc(int i, int j, vector<vector<int>> &mp)
{
    // cout << i << ' ' << j << '\n';
    if (i == N)
    {
        for (auto &line : mp)
        {
            for (auto elem : line)
                cout << elem << ' ';
            cout << '\n';
        }
        cout << '\n';
        return;
    }
    int ni = i + (j + 1 == M);
    int nj = (j + 1) % M;
    for (int u = 1; u < 4; ++u)
    {
        mp[i][j] = u;
        if (check(i, j, mp))
            calc(ni, nj, mp);
    }
}

int main()
{
    vector<vector<int>> mp(N, vector<int>(M, -1));
    calc(0, 0, mp);
}