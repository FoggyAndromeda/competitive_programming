#include <bits\stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

using piu = pair<int, uint64_t>;

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

const int max_n = 10002;

const vector<piu> powers = []()
{
    mt19937 gen(chrono::high_resolution_clock::now().time_since_epoch().count());
    int p = 2 * uniform_int_distribution<int>(mod / 4, (mod - 4) / 2)(gen) + 1;
    vector<piu> result(max_n);
    result[0] = {1, 1};
    for (int i = 1; i < max_n; ++i)
        result[i] = result[i - 1] * piu{p, p};
    return result;
}();

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<piu> straight_hashes(n), reverse_hashes(n);
    straight_hashes[0] = {s[0], s[0]};
    for (int i = 1; i < n; ++i)
    {
        straight_hashes[i] = straight_hashes[i - 1] * powers[1] + piu{s[i], s[i]};
    }
    reverse_hashes[n - 1] = {s[n - 1], s[n - 1]};
    for (int i = n - 2; i > -1; --i)
    {
        reverse_hashes[i] = reverse_hashes[i + 1] * powers[1] + piu{s[i], s[i]};
    }

    function<piu(int, int)> straight_subhash = [&](int i, int j)
    {
        if (i == 0)
            return straight_hashes[j];
        return straight_hashes[j] - straight_hashes[i - 1] * powers[j - i + 1];
    };

    function<piu(int, int)> reverse_subhash = [&](int i, int j)
    {
        if (j == n - 1)
            return reverse_hashes[i];
        int rev_i = s.length() - 1 - i;
        int rev_j = s.length() - 1 - j;
        return reverse_hashes[i] - reverse_hashes[j + 1] * powers[rev_i - rev_j + 1];
    };

    int len_poli = 0;
    for (int i = 1; i < n; ++i)
        if (straight_subhash(n - i, n - 1) == reverse_subhash(n - i, n - 1))
            len_poli = i;
    cout << s;
    for (int i = n - 1 - len_poli; i > -1; --i)
        cout << s[i];
    cout << '\n';
}