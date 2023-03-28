#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    unordered_map<string, int> scores;
    list<pair<string, int>> moves;
    for (int i = 0; i < n; ++i)
    {
        string s;
        int a;
        cin >> s >> a;
        scores[s] += a;
        moves.push_back({s, a});
    };
    unordered_set<string> winners;
    for (auto &[s, a] : scores)
    {
        if (winners.size() == 0)
        {
            winners.insert(s);
            continue;
        }
        if (a < scores[*winners.begin()])
            continue;
        if (a == scores[*winners.begin()])
            winners.insert(s);
        if (a > scores[*winners.begin()])
        {
            winners.clear();
            winners.insert(s);
        }
    }
    if (winners.size() == 1)
    {
        cout << *winners.begin() << '\n';
        return 0;
    }
    int m = scores[*winners.begin()];
    scores.clear();
    for (auto &[s, a] : moves)
    {
        if (winners.find(s) == winners.end())
            continue;
        scores[s] += a;
        if (scores[s] >= m)
        {
            cout << s << '\n';
            break;
        }
    }
}