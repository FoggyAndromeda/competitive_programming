#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    unordered_map<int, int> last_ind;

    vector<int> ans(n, 1), prev(n, -1);
    for (int i = 0; i < n; ++i)
    {
        if (last_ind.find(a[i] - 1) != last_ind.end())
        {
            ans[i] = ans[last_ind[a[i] - 1]] + 1;
            prev[i] = last_ind[a[i] - 1];
        }
        last_ind[a[i]] = i;
    }

    int res = *max_element(ans.begin(), ans.end());
    cout << res << '\n';

    for (int i = 0; i < n; ++i)
    {
        if (ans[i] == res)
        {
            int p = i;
            stack<int> s;
            do
            {
                s.push(p);
                p = prev[p];
            } while (p != -1);

            while (!s.empty())
            {
                cout << s.top() + 1 << ' ';
                s.pop();
            }
            cout << '\n';
            break;
        }
    }
}