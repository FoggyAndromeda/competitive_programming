#include <bits/stdc++.h>

using namespace std;

unordered_map<char, int> dict = []()
{
    unordered_map<char, int> res;

    int now = 0;
    for (char c = '0'; c <= '9'; ++c)
        res[c] = now++;
    for (char c = 'A'; c <= 'Z'; ++c)
        res[c] = now++;

    return res;
}();

string s;
bool check_base(int base)
{
    int now_res = 0;
    for (char c : s)
    {
        if (dict[c] >= base)
            return false;
        now_res += dict[c];
    }
    if (now_res % (base - 1) == 0)
        return true;
    return false;
}

int main()
{
    cin >> s;
    int ans = -1;
    for (int i = 2; i < 37; ++i)
        if (check_base(i))
        {
            ans = i;
            break;
        }
    if (ans == -1)
        cout << "No solution.\n";
    else
        cout << ans << '\n';
}