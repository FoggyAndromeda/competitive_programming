#include <bits/stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    set<int> psbl;
    int n = s.size();
    for (int i = 0; i < n; ++i)
    {
        int now_num = s[i] - '0';
        psbl.insert(now_num);
        now_num *= 10;
        for (int j = i + 1; j < n; ++j)
        {
            now_num += s[j] - '0';
            psbl.insert(now_num);
            for (int k = j + 1; k < n; ++k)
                psbl.insert(now_num * 10 + s[k] - '0');
            now_num -= s[j] - '0';
        }
    }
    bool found = false;
    for (int elem : psbl)
    {
        if (elem % 8 == 0)
        {
            cout << "YES\n"
                 << elem << '\n';
            found = true;
            break;
        }
    }
    if (!found)
        cout << "NO\n";
}