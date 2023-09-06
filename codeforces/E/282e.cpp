#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int maxn = 1e5 + 1;
const int num_bit = 40;

vector<vector<int>> trie(maxn *num_bit, vector<int>(2, -1));
int trie_index = 1;

void trie_insert(int a)
{
    int vertex = 0;
    for (int i = num_bit; i > -1; --i)
    {
        int bit = (a >> i) & 1;
        if (trie[vertex][bit] == -1)
            trie[vertex][bit] = trie_index++;
        vertex = trie[vertex][bit];
    }
}

int trie_find(int a)
{
    int vertex = 0;
    int result = 0;
    for (int i = num_bit; i > -1; --i)
    {
        int bit = (a >> i) & 1;
        bit ^= trie[vertex][bit ^ 1] != -1;
        result |= bit << i;
        vertex = trie[vertex][bit];
    }
    return result;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    vector<int> pref(n);
    pref[0] = a[0];
    for (int i = 1; i < n; ++i)
        pref[i] = pref[i - 1] ^ a[i];

    int now_suff = 0;
    int ans = 0;
    trie_insert(0);
    for (int i = n - 1; i > -1; --i)
    {
        ans = max(ans, pref[i] ^ trie_find(pref[i]));
        now_suff ^= a[i];
        trie_insert(now_suff);
    }
    ans = max(ans, trie_find(0));
    cout << ans << '\n';
}
