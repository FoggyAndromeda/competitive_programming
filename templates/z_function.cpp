vector<int> zfunction(string &s)
{
    int n = s.size();
    vector<int> res(n, 0);
    res[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
            res[i] = min(r - i + 1, res[i - l]);
        while (i + res[i] < n && s[res[i]] == s[i + res[i]])
            ++res[i];
        if (i + res[i] - 1 > r)
        {
            l = i;
            r = i + res[i] - 1;
        }
    }

    return res;
}