#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5 + 1;
const int alphabet_size = 26;

vector<vector<int>> trie(maxn, vector<int>(alphabet_size, -1));

int trie_size = 1;

void trie_insert(const string &s)
{
    int v = 0;
    for (char c : s)
    {
        int i = c - 'a';
        if (trie[v][i] == -1)
            trie[v][i] = trie_size++;
        v = trie[v][i];
    }
}

bool will_first_win(int);
bool will_second_win(int);
bool will_first_loose(int);
bool will_second_loose(int);

bool will_first_win(int v = 0)
{
    bool result = false;
    for (int nxt = 0; nxt < alphabet_size; ++nxt)
    {
        if (trie[v][nxt] == -1)
            continue;
        result = result || !will_second_win(trie[v][nxt]);
    }
    return result;
}

bool will_second_win(int v)
{
    bool result = false;
    for (int nxt = 0; nxt < alphabet_size; ++nxt)
    {
        if (trie[v][nxt] == -1)
            continue;
        result = result || !will_first_win(trie[v][nxt]);
    }
    return result;
}

bool will_first_loose(int v = 0)
{
    bool result = false;
    bool is_leaf = true;
    for (int nxt = 0; nxt < alphabet_size; ++nxt)
    {
        if (trie[v][nxt] == -1)
            continue;
        is_leaf = false;
        result = result || !will_second_loose(trie[v][nxt]);
    }
    return is_leaf || result;
}

bool will_second_loose(int v)
{
    bool result = false;
    bool is_leaf = true;
    for (int nxt = 0; nxt < alphabet_size; ++nxt)
    {
        if (trie[v][nxt] == -1)
            continue;
        is_leaf = false;
        result = result || !will_first_loose(trie[v][nxt]);
    }
    return is_leaf || result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        trie_insert(s);
        // clog << will_first_win() << ' ' << will_first_loose() << '\n';
    }
    bool wfw = will_first_win();
    bool wfl = will_first_loose();
    // clog << wfw << wfl << '\n';
    if (!wfw)
    {
        cout << "Second\n";
        return 0;
    }
    if (wfl)
    {
        cout << "First\n";
        return 0;
    }
    if (k % 2 == 0)
        cout << "Second\n";
    else
        cout << "First\n";
}
