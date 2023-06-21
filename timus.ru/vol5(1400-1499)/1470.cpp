#include <bits/stdc++.h>

using namespace std;

#define maxn 130
#define int int64_t

struct fenwick
{
    vector<vector<vector<int>>> tree;

    fenwick()
    {
        tree.assign(maxn, vector<vector<int>>(maxn, vector<int>(maxn, 0)));
    }

    void add(int x, int y, int z, int d)
    {
        for (int i = x + 1; i < maxn; i += i & -i)
            for (int j = y + 1; j < maxn; j += j & -j)
                for (int k = z + 1; k < maxn; k += k & -k)
                    tree[i][j][k] += d;
    }

    int result(int x, int y, int z)
    {
        int res = 0;
        for (int i = x + 1; i > 0; i -= i & -i)
            for (int j = y + 1; j > 0; j -= j & -j)
                for (int k = z + 1; k > 0; k -= k & -k)
                    res += tree[i][j][k];
        return res;
    }

    int res(int x1, int y1, int z1, int x2, int y2, int z2)
    {
        return result(x2, y2, z2) - result(x1 - 1, y2, z2) - result(x2, y1 - 1, z2) - result(x2, y2, z1 - 1) +
               result(x1 - 1, y1 - 1, z2) + result(x1 - 1, y2, z1 - 1) + result(x2, y1 - 1, z1 - 1) -
               result(x1 - 1, y1 - 1, z1 - 1);
    }
};

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    fenwick ft;
    while (1)
    {
        int t;
        cin >> t;
        if (t == 3)
            break;
        if (t == 1)
        {
            int x, y, z, k;
            cin >> x >> y >> z >> k;
            ft.add(x, y, z, k);
        }
        else
        {
            int x1, y1, z1, x2, y2, z2;
            cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2;
            cout << ft.res(x1, y1, z1, x2, y2, z2) << '\n';
        }
    }
}