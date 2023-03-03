#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>

using namespace std;
using ui64 = uint64_t;
using piu = pair<int, uint32_t>;

const int mod = 1e9 + 7;

piu operator+(piu f, piu s)
{
    return {(0LL + f.first + s.first) % mod, f.second + s.second};
}

piu operator-(piu f, piu s)
{
    return {(0LL + f.first - s.first + mod) % mod, f.second - s.second};
}

piu operator*(piu f, piu s)
{
    return {(1LL * f.first * s.first) % mod, f.second * s.second};
}

const int maxn = 5e4;
vector<piu> powers = []()
{
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    int p = 2 * uniform_int_distribution<int>(mod / 4, (mod - 10) / 2)(gen) + 1;

    vector<piu> res(maxn);
    res[0] = {1, 1};
    res[1] = {p, p};

    for (int i = 2; i < maxn; ++i)
        res[i] = res[i - 1] * res[1];

    return res;
}();

class Hash
{
private:
    vector<piu> h;
    int n;

public:
    Hash(const string &s)
    {
        n = s.size();
        h.assign(n, {s[0], s[0]});
        for (int i = 1; i < n; ++i)
            h[i] = h[i - 1] * powers[1] + piu{s[i], s[i]};
    }

    piu sub(int l, int r)
    {
        if (l == 0)
            return h[r];
        return h[r] - h[l - 1] * powers[r - l + 1];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    Hash str(s);
    reverse(s.begin(), s.end());
    Hash rev(s);
    int n = s.size();

    vector<int> prev(n), counter(n, n + 1);
    for (int i = 0; i < n; ++i)
    {
        if (str.sub(0, i) == rev.sub(n - i - 1, n - 1))
        {
            prev[i] = 0;
            counter[i] = 1;
            continue;
        }
        for (int j = 0; j < i; ++j)
            if (str.sub(j + 1, i) == rev.sub(n - i - 1, n - j - 2) && counter[i] > counter[j] + 1)
            {
                counter[i] = counter[j] + 1;
                prev[i] = j + 1;
            }
    }
    cout << counter[n - 1] << '\n';

    unordered_set<int> ans;
    int i = n - 1;
    while (i >= 0)
    {
        ans.insert(i);
        i = prev[i] - 1;
    }

    for (int i = n - 1; i > -1; --i)
    {
        cout << s[i];
        if (ans.find(n - i - 1) != ans.end())
            cout << ' ';
    }
    cout.flush();
}