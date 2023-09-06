#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1;

// vector<vector<int>> trie(30 * maxn, vector<int>(2, -1));
int trie[30 * maxn][2];
int trie_size = 1;

void insert_trie(int a)
{
    int v = 0;
    for (int i = 30; i > -1; --i)
    {
        int bit = (a >> i) & 1;
        if (trie[v][bit] == -1)
            trie[v][bit] = trie_size++;
        v = trie[v][bit];
    }
}

int find_ans(int v, int power)
{
    if (trie[v][1] == -1 && trie[v][0] == -1)
        return 0;
    if (trie[v][1] == -1)
        return find_ans(trie[v][0], power - 1);
    if (trie[v][0] == -1)
        return find_ans(trie[v][1], power - 1);
    return (1 << power) | min(find_ans(trie[v][0], power - 1), find_ans(trie[v][1], power - 1));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    fill(begin(trie[0]), end(trie[0]), -1);
    fill(begin(trie[1]), end(trie[1]), -1);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        insert_trie(a[i]);
    }
    int x = find_ans(0, 30);
    cout << x << '\n';
}
