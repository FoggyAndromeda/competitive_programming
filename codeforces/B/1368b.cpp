#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const string cf = "codeforces";

int main()
{
    i64 k;
    cin >> k;
    vector<i64> res(cf.size(), 1);
    i64 mult = 1;
    i64 i = 0;
    while (mult < k)
    {
        mult = mult / res[i] * (res[i] + 1);
        ++res[i];
        i = (i + 1) % cf.size();
    }
    for (i64 i = 0; i < cf.size(); ++i)
    {
        for (i64 j = 0; j < res[i]; ++j)
            cout << cf[i];
    }
    cout << endl;
}