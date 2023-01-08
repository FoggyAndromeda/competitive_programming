#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> p[i];
        --p[i];
    }
    vector<int> lens;
    vector<bool> used(n, false);
    for (int i = 0; i < n; ++i)
    {
        if (used[i])
            continue;
        int now_len = 0;
        int j = i;
        do
        {
            used[j] = true;
            j = p[j];
            ++now_len;
        } while (j != i);
        lens.push_back(now_len);
    }
    int ans = lens[0];
    for (int i = 1; i < lens.size(); ++i)
        ans = lcm(ans, lens[i]);
    cout << ans << '\n';
}