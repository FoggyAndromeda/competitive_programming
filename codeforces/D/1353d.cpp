#include <bits/stdc++.h>

using namespace std;

struct pii
{
    int first;
    int second;

    pii(int a, int b)
    {
        first = a;
        second = b;
    }
};

bool operator<(pii f, pii s)
{
    int df = f.second - f.first, ds = s.second - s.first;
    return (df < ds) || (df == ds && f.first > s.first);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> ans(n);
    int i = 0;
    priority_queue<pii> s;
    s.emplace(0, n - 1);
    while (!s.empty())
    {
        int l, r;
        l = s.top().first;
        r = s.top().second;
        s.pop();
        if (l > r)
            continue;
        int m = (l + r) / 2;
        ans[m] = ++i;
        if (l == r)
            continue;
        s.emplace(l, m - 1);
        s.emplace(m + 1, r);
    }
    for (int elem : ans)
        cout << elem << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}