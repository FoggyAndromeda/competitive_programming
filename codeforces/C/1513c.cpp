#include <bits/stdc++.h>

using namespace std;

// map<pair<int, int>, int> visited;

#define maxn 300'000
#define mod 1'000'000'007

vector<vector<int>> precalc(maxn, vector<int>(10, 0));

inline int res(int a, int n)
{
    // if (n < 0)
    //     return 0;
    // if (a + n < 10)
    //     return 1;
    // if (visited.find({a, n}) != visited.end())
    //     return visited[{a, n}];
    // int ans = res(1, n - (10 - a)) + res(0, n - (10 - a));
    // visited[{a, n}] = ans;
    // return ans;
    return precalc[n][a];
}

void precalculate()
{
    for (int i = 0; i < maxn; ++i)
        for (int j = 0; j < 10; ++j)
        {
            if (j + i >= 10)
                precalc[i][j] = (precalc[i - (10 - j)][1] + precalc[i - (10 - j)][0]) % mod;
            else
                precalc[i][j] = 1;
        }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> cnt(10, 0);

    while (n > 0)
    {
        ++cnt[n % 10];
        n /= 10;
    }
    int ans = 0;
    for (int i = 0; i < 10; ++i)
        ans = (0ll + ans + 1ll * cnt[i] * res(i, m)) % mod;
    cout << ans << '\n';
}

int main()
{
    precalculate();
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}