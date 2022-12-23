#include <bits/stdc++.h>

using namespace std;

int main()
{
    unordered_map<int, vector<int>> numbers;
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int a;
        cin >> a;
        numbers[a].push_back(i);
    }
    for (auto &[key, vec] : numbers)
        vec.push_back(1e9 + 10);

    int q;
    cin >> q;
    for (int i = 0; i < q; ++i)
    {
        int l, r, a;
        cin >> l >> r >> a;
        if (!numbers.count(a))
        {
            cout << 0;
            continue;
        }
        int llow = *lower_bound(numbers[a].begin(), numbers[a].end(), l);
        int lupp = *upper_bound(numbers[a].begin(), numbers[a].end(), l);
        int rlow = *lower_bound(numbers[a].begin(), numbers[a].end(), r);
        int rupp = *upper_bound(numbers[a].begin(), numbers[a].end(), r);
        if ((l <= llow && llow <= r) || (l <= lupp && lupp <= r) || (l <= rlow && rlow <= r) || (l <= rupp && rupp <= r))
            cout << 1;
        else
            cout << 0;
    }
}