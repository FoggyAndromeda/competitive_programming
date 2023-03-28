#include <bits/stdc++.h>

using namespace std;

int ans = 0;
int n, k;
vector<bool> used(10, false);

void calculate(vector<int> &a)
{
    if (a.size() == n)
    {
        int count_unmoved = 0;
        for (int i = 0; i < n; ++i)
            if (a[i] == i)
                ++count_unmoved;
        if (count_unmoved == k)
            ++ans;
        return;
    }
    for (int i = 0; i < n; ++i)
    {
        if (used[i])
            continue;
        a.push_back(i);
        used[i] = true;
        calculate(a);
        a.pop_back();
        used[i] = false;
    }
}

int main()
{
    cin >> n >> k;
    vector<int> path;
    calculate(path);
    cout << ans << '\n';
}