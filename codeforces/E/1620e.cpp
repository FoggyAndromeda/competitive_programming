#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int q;
    cin >> q;
    int ans_len = 0;
    vector<list<int>> indexes(500'001);
    while (q-- > 0)
    {
        int type;
        cin >> type;
        if (type == 1)
        {
            ++ans_len;
            int x;
            cin >> x;
            indexes[x].push_back(ans_len - 1);
        }
        else
        {
            int x, y;
            cin >> x >> y;
            indexes[y].splice(indexes[y].end(), indexes[x]);
        }
    }
    vector<int> ans(ans_len);
    for (int i = 0; i < 500'001; ++i)
        for (int j : indexes[i])
            ans[j] = i;
    for (int i : ans)
        cout << i << ' ';
    cout << '\n';
}