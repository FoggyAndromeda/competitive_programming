#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < 2 * n; ++i)
    {
        for (int row = i, col = 0; row > -1; --row, ++col)
        {
            if (row < n && col < n)
                cout << a[row][col] << ' ';
        }
    }
}