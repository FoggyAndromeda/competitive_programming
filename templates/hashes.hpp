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
