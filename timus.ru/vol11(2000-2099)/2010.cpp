#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>

using namespace std;

int n, x, y;

int straights()
{
    return (n - 1) * 2;
}

int knight()
{
    const vector<pair<int, int>> deltas = {{1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};
    int ans = 0;
    for (auto [dx, dy] : deltas)
    {
        if (x + dx < 1 || x + dx > n)
            continue;
        if (y + dy < 1 || y + dy > n)
            continue;
        ++ans;
    }
    return ans;
}

int king()
{
    const vector<pair<int, int>> deltas = {{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
    int ans = 0;
    for (auto [dx, dy] : deltas)
    {
        if (x + dx < 1 || x + dx > n)
            continue;
        if (y + dy < 1 || y + dy > n)
            continue;
        ++ans;
    }
    return ans;
}

int diag()
{
    static int ans = 0;
    if (ans != 0)
        return ans;
    for (int i = 1; i <= n; ++i)
    {
        int now_y = x + y - i;
        if (now_y >= 1 && now_y <= n)
            ++ans;
        now_y = x - y + i;
        if (now_y >= 1 && now_y <= n)
            ++ans;
    }
    ans -= 2;
    return ans;
}

int main()
{
    cin >> n >> x >> y;
    cout << "King: " << king() << '\n';
    cout << "Knight: " << knight() << '\n';
    cout << "Bishop: " << diag() << '\n';
    cout << "Rook: " << straights() << '\n';
    cout << "Queen: " << diag() + straights() << '\n';
}