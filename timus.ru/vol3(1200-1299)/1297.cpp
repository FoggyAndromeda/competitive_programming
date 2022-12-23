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

const int max_n = 1001;

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
    vector<piu> straight_hash(s.length());
    straight_hash[0] = {s[0], s[0]};
    for (int i = 1; i < s.length(); ++i)
        straight_hash[i] = straight_hash[i - 1] * powers[1] + piu{s[i], s[i]};
    function<piu(int, int)> straight_subhash = [&](int i, int j)
    {
        if (i == 0)
            return straight_hash[j];
        return straight_hash[j] - straight_hash[i - 1] * powers[j - i + 1];
    };
    vector<piu> reverse_hash(s.length());
    reverse_hash[s.length() - 1] = {s[s.length() - 1], s[s.length() - 1]};
    for (int i = s.length() - 2; i > -1; --i)
        reverse_hash[i] = reverse_hash[i + 1] * powers[1] + piu{s[i], s[i]};
    function<piu(int, int)> reverse_subhash = [&](int i, int j)
    {
        if (j == s.length() - 1)
            return reverse_hash[i];
        // индексы в реверснутой строке
        int rev_i = s.length() - 1 - i;
        int rev_j = s.length() - 1 - j;
        return reverse_hash[i] - reverse_hash[j + 1] * powers[rev_i - rev_j + 1];
    };
    for (int len_pali = s.length(); len_pali > 0; --len_pali)
    {
        for (int i = 0; i + len_pali - 1 < s.length(); ++i)
        {
            if (straight_subhash(i, i + len_pali - 1) == reverse_subhash(i, i + len_pali - 1))
            {
                cout << s.substr(i, len_pali) << '\n';
                exit(0);
            }
        }
    }
}