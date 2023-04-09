#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> p(2 * n);
    for (int i = 0; i < 2 * n; ++i)
        cin >> p[i];

    vector<int> prs(2 * n, -1);
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        --a;
        --b;
        prs[a] = b;
        prs[b] = a;
    }
    int now_player;
    cin >> now_player;
    now_player %= 2;

    int last_choice = -1;
    unordered_set<int> taken;
    for (int i = 0; i < 2 * n; ++i)
    {
        if (now_player)
        {
            int now = -1;
            if (last_choice != -1 && prs[last_choice] != -1 && taken.find(prs[last_choice]) == taken.end())
                now = prs[last_choice];
            else
            {
                bool found = false;
                for (int i = 0; i < 2 * n; ++i)
                {
                    if (prs[i] != -1 && taken.find(i) == taken.end())
                    {
                        if (p[i] > p[prs[i]])
                            now = i;
                        else
                            now = prs[i];
                        found = true;
                        break;
                    }
                }
                if (!found)
                    for (int i = 0; i < 2 * n; ++i)
                    {
                        if (taken.find(i) != taken.end())
                            continue;
                        if (now == -1 || p[i] > p[now])
                            now = i;
                    }
            }
            taken.insert(now);
            cout << now + 1 << '\n';
        }
        else
        {
            int now;
            cin >> now;
            taken.insert(now - 1);
            last_choice = now - 1;
        }
        now_player = (now_player + 1) % 2;
    }
}