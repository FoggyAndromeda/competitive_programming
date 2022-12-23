#include <bits\stdc++.h>

using namespace std;

const vector<pair<char, char>> deltas = {
    {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {2, 1}, {2, -1}, {-2, 1}, {-2, -1}};

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
    {
        string s;
        cin >> s;
        int ans = 0;
        for (auto [dx, dy] : deltas)
        {
            if (s[0] - dx >= 'a' && s[0] - dx <= 'h' && s[1] - dy >= '1' && s[1] - dy <= '8')
                ++ans;
        }
        cout << ans << '\n';
    }
}