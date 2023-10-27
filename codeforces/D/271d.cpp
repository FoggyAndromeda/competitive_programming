// #pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

using ui64 = uint64_t;
using piu = pair<int, ui64>;

const int mod = 1e9 + 7;
const int maxn = 1e6;

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
    string al;
    cin >> al;
    int k;
    cin >> k;

    Hash h(s);
    int n = s.size();

    vector<int> pref(n, 0);
    pref[0] = 1 - al[s[0] - 'a'] + '0';
    for (int i = 1; i < n; ++i)
        pref[i] = pref[i - 1] + (1 - al[s[i] - 'a'] + '0');

    // for (int i : pref)
    //     clog << i << ' ';

    function<int(int, int)> rq = [&](int l, int r)
    {
        if (l == 0)
            return pref[r];
        return pref[r] - pref[l - 1];
    };

    vector<piu> ans;
    for (int i = 0; i < n; ++i)
    {
        int l = -1, r = i + 1;
        while (r - l > 1)
        {
            int mid = (l + r) >> 1;
            if (rq(mid, i) > k)
                l = mid;
            else
                r = mid;
        }
        // clog << r << ' ' << i << '\n';
        for (int j = r; j <= i; ++j)
        {
            ans.push_back(h.sub(j, i));
        }
    }
    sort(ans.begin(), ans.end());
    cout << unique(ans.begin(), ans.end()) - ans.begin() << '\n';
}