#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2")

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;
    function<bool(int, int, int, int)> eq = [&](int l1, int r1, int l2, int r2)
    {
        if (r1 - l1 == 1)
            return (s1[l1] == s2[l2] && s1[r1] == s2[r2]) || (s1[l1] == s2[r2] && s1[r1] == s2[l2]);
        if ((r1 - l1 + 1) % 2 == 1)
        {
            for (int i = 0; i <= r1 - l1; ++i)
                if (s1[l1 + i] != s2[l2 + i])
                    return false;
            return true;
        }
        int m1 = (l1 + r1) >> 1;
        int m2 = (l2 + r2) >> 1;
        bool res = eq(l1, m1, l2, m2) && eq(m1 + 1, r1, m2 + 1, r2);
        res = res || (eq(l1, m1, m2 + 1, r2) && eq(m1 + 1, r1, l2, m2));
        return res;
    };
    if (eq(0, s1.size() - 1, 0, s2.size() - 1))
        cout << "YES\n";
    else
        cout << "NO\n";
}