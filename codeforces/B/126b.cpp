#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

using ui64 = uint64_t;
using piu = pair<int, ui64>;

const int mod = 1e9 + 7;
const int maxn = 1e6 + 1;

piu operator+(piu a, piu b)
{
    return {(0LL + a.first + b.first) % mod, a.second + b.second};
}

piu operator-(piu a, piu b)
{
    return {(0LL + a.first - b.first + mod) % mod, a.second - b.second};
}

piu operator*(piu a, piu b)
{
    return {(1LL * a.first * b.first) % mod, a.second * b.second};
}

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

    piu sub(int l, int r) const
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
    Hash h(s);
    int n = s.size();
    vector<int> possible_answers;
    for (int i = n - 2; i > 0; --i)
        if (h.sub(0, i - 1) == h.sub(n - i, n - 1))
            possible_answers.push_back(i);
    // for (int i : possible_answers)
    //     clog << i << ' ';
    // clog << '\n';

    int ans = -1;
    for (int l : possible_answers)
    {
        for (int j = 1; j < n - l; ++j)
            if (h.sub(j, j + l - 1) == h.sub(0, l - 1))
            {
                ans = l;
                break;
            }
        if (ans != -1)
            break;
    }

    if (ans == -1)
        cout << "Just a legend";
    else
        for (int i = 0; i < ans; ++i)
            cout << s[i];
    cout << '\n';
}