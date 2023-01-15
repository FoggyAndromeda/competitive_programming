#include <bits/stdc++.h>

using namespace std;

// length of longest suffix equal to prefix
vector<int> prefixf(string &s)
{
    int n = s.size();
    vector<int> res(n, 0);
    for (int i = 1; i < n; ++i)
    {
        int j = res[i - 1];
        while (j > 0 && s[i] != s[j])
            j = res[j - 1];
        if (s[i] == s[j])
            ++j;
        res[i] = j;
    }
    return res;
}

int main()
{
}