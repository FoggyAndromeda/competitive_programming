#include <bits/stdc++.h>

using namespace std;

const vector<vector<int>> transitions = {
    {},
    {-1, 2, 0, 0, -1, 0, -1, 0, 0, 0},
    {-1, 4, 3, 0, -1, 9, -1, 0, 0, 0},
    {-1, 6, 0, 0, 8, 0, -1, 0, 0, 0},
    {-1, 5, 0, 0, -1, 0, -1, 0, 0, 0},
    {-1, -1, 0, 0, -1, 0, 7, 0, 0, 0}};

const set<int> final_states = {2, 3, 5, 7, 8, 9};

void solve()
{
    // string s;
    // cin >> s;
    string sub;
    list<int> word;
    /*
    let out = 1, put = 2, on = 3, in = 4, e = 5
    */
    bool ans = true;
    char c = getchar();
    while ('a' <= c && c <= 'z')
    {
        if (ans)
            sub.push_back(c);
        if (sub.size() > 3)
            ans = false;
        if (sub == "e")
        {
            word.push_back(5);
            sub.clear();
        }
        if (sub == "in")
        {
            word.push_back(4);
            sub.clear();
        }
        if (sub == "on")
        {
            word.push_back(3);
            sub.clear();
        }
        if (sub == "put")
        {
            word.push_back(2);
            sub.clear();
        }
        if (sub == "out")
        {
            word.push_back(1);
            sub.clear();
        }
        c = getchar();
    }

    if (sub.size() > 0)
        ans = false;

    if (!ans)
    {
        cout << "NO\n";
        return;
    }

    int state = 1;
    for (int c : word)
    {
        if (transitions[c][state] == -1)
        {
            ans = false;
            break;
        }
        if (transitions[c][state] > 0)
            state = transitions[c][state];
        else if (transitions[c][state] == 0)
        {
            state = transitions[c][1];
            if (state == -1)
            {
                ans = false;
                break;
            }
        }
    }
    if (!ans || final_states.find(state) == final_states.end())
        cout << "NO\n";
    else
        cout << "YES\n";
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}