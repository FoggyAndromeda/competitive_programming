#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int now_num = 1;
    for (int i = 0; i < 2 * n; ++i)
    {
        for (int col = i, row = 0; col > -1; ++row, --col)
        {
            if (col < n && row < n)
            {
                a[row][col] = now_num;
                ++now_num;
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = n - 1; j > -1; --j)
        {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}