#pragma GCC optimize("Ofast,unroll-loops")
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

piu sumgeom(int n)
{
    if (n == 0)
        return {0, 0};
    if (n == 1)
        return powers[0];
    if (n & 1)
        return powers[0] + powers[1] * sumgeom(n - 1);
    piu half = sumgeom(n / 2);
    return half + powers[n / 2] * half;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    for (int i = 0; i < n; ++i)
        s[i] -= '0';
    vector<int> pref(n);
    pref[0] = s[0];

    for (int i = 1; i < n; ++i)
        pref[i] = pref[i - 1] + s[i];

    Hash h(s);
    set<piu> ans;

    for (int t = 0; t < m; ++t)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        piu power = powers[n - r - 1];
        piu now_hash = h.sub(0, n - 1) - h.sub(l, r) * power;
        int cnt_ones = pref[r];
        if (l > 0)
            cnt_ones -= pref[l - 1];
        piu inserted = sumgeom(cnt_ones);
        now_hash = now_hash + inserted * power;
        ans.insert(now_hash);
    }
    cout << ans.size() << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}
