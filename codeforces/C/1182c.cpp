#include <bits/stdc++.h>

using namespace std;

inline bool check(char c)
{
    return c == 'a' || c == 'e' || c == 'o' || c == 'i' || c == 'u';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<string> inp(n);
    map<pair<int, char>, stack<int>> words;
    for (int k = 0; k < n; ++k)
    {
        cin >> inp[k];
        int cnt = 0;
        char last;
        for (int i = 0; i < inp[k].size(); ++i)
            if (check(inp[k][i]))
            {
                ++cnt;
                last = inp[k][i];
            }
        words[{cnt, last}].push(k);
    }

    vector<pair<int, int>> samelenandlast;

    map<int, stack<int>> leftwords;
    for (auto &[p, s] : words)
    {
        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            samelenandlast.push_back({a, b});
        }
        if (s.size() == 1)
            leftwords[p.first].push(s.top());
    }

    vector<pair<int, int>> samelen;
    for (auto &[p, s] : leftwords)
    {
        while (s.size() > 1)
        {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            samelen.push_back({a, b});
        }
    }

    vector<pair<pair<int, int>, pair<int, int>>> ans;

    int i = 0;
    for (; i < min(samelen.size(), samelenandlast.size()); ++i)
        ans.emplace_back(samelen[i], samelenandlast[i]);
    for (; i + 1 < samelenandlast.size(); i += 2)
        ans.emplace_back(samelenandlast[i], samelenandlast[i + 1]);

    cout << ans.size() << '\n';

    for (auto [beg, en] : ans)
    {
        cout << inp[beg.first] << ' ' << inp[en.first] << '\n';
        cout << inp[beg.second] << ' ' << inp[en.second] << '\n';
    }
}