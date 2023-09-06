#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<vector<char>> field(3, vector<char>(3));
    int cntz = 0, cntc = 0;
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cin >> field[i][j];
            cntz += field[i][j] == '0';
            cntc += field[i][j] == 'X';
        }
    }
    bool now_first = cntc == cntz;
    bool first_won = false, second_won = false;
    for (int i = 0; i < 3; ++i)
    {
        first_won |= field[i][0] == 'X' && field[i][1] == 'X' && field[i][2] == 'X';
        first_won |= field[0][i] == 'X' && field[1][i] == 'X' && field[2][i] == 'X';
        second_won |= field[i][0] == '0' && field[i][1] == '0' && field[i][2] == '0';
        second_won |= field[0][i] == '0' && field[1][i] == '0' && field[2][i] == '0';
    }

    first_won |= field[0][0] == 'X' && field[1][1] == 'X' && field[2][2] == 'X';
    first_won |= field[0][2] == 'X' && field[1][1] == 'X' && field[2][0] == 'X';
    second_won |= field[0][0] == '0' && field[1][1] == '0' && field[2][2] == '0';
    second_won |= field[0][2] == '0' && field[1][1] == '0' && field[2][0] == '0';

    if (cntc - cntz > 1 || cntc - cntz < 0 || (first_won && second_won) || (first_won && now_first) || (second_won && !now_first))
    {
        cout << "illegal\n";
        return 0;
    }
    if (cntc + cntz == 9 && !first_won && !second_won)
    {
        cout << "draw\n";
        return 0;
    }
    if (first_won)
    {
        cout << "the first player won\n";
        return 0;
    }
    if (second_won)
    {
        cout << "the second player won\n";
        return 0;
    }
    if (now_first)
    {
        cout << "first\n";
        return 0;
    }
    cout << "second\n";
    return 0;
}