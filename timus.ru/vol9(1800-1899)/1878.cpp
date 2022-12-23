#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<int>> moves = {
        {0, 3, 15, 12},
        {1, 7, 14, 8},
        {4, 2, 11, 13},
        {5, 6, 10, 9}};

    vector<int> cube(16);
    for (int i = 0; i < 16; ++i)
        cin >> cube[i];

    vector<int> lu = {0, 1, 4, 5};
    vector<int> count_lu_colors(5, 0);

    for (int i : lu)
        ++count_lu_colors[cube[i]];

    int color_of_lu = 1;
    for (int i = 2; i < 5; ++i)
        if (count_lu_colors[i] > count_lu_colors[color_of_lu])
            color_of_lu = i;

    map<int, int> moves_for_ul = {{0, 0}, {1, 1}, {4, 2}, {5, 3}};
    int ans = 0;
    for (int i : lu)
    {
        if (cube[i] == color_of_lu)
            continue;

        vector<int> mvs = moves[moves_for_ul[i]];

        int j;
        for (int k = 1; k < 4; ++k)
            if (cube[mvs[k]] == color_of_lu)
                j = k;

        ans += min(j, 4 - j);
    }
    cout << ans << '\n';
}