#include <bits\stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    string res = s;
    int now_delta = 5;
    for (int i = 0; i < s.size(); ++i)
    {
        int now_num = s[i] - 'a';
        now_num -= now_delta;
        while (now_num < 0)
            now_num += 26;
        res[i] = 'a' + now_num;
        now_delta = now_num + now_delta;
    }
    cout << res << '\n';
}