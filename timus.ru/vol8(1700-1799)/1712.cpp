#include <bits\stdc++.h>

using namespace std;

int main()
{
    vector<pair<int, int>> windows;
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
        {
            char c;
            cin >> c;
            if (c == 'X')
                windows.push_back({i, j});
        }
    }
    vector<vector<char>> mp(4, vector<char>(4));
    for (int i = 0; i < 4; ++i)
    {
        for (int j = 0; j < 4; ++j)
            cin >> mp[i][j];
    }
    function<void()> rotate = [&]()
    {
        for (int i = 0; i < 4; ++i)
        {
            windows[i] = {windows[i].second, 3 - windows[i].first};
        }
        sort(windows.begin(), windows.end());
    };

    for (int x = 0; x < 4; ++x)
    {
        for (auto [i, j] : windows)
        {
            cout << mp[i][j];
        }
        rotate();
    }
    cout << '\n';
}