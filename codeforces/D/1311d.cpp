#include <bits/stdc++.h>

using namespace std;

struct triple
{
    int a, b, c;
};

int dist(triple a, triple b)
{
    return abs(a.a - b.a) + abs(a.b - b.b) + abs(a.c - b.c);
}

void solve()
{
    triple init;
    cin >> init.a >> init.b >> init.c;
    triple ans{1, 1, 1};
    triple now{1, 1, 1};
    for (; now.a <= 20'000; ++now.a)
        for (now.b = now.a; now.b <= 20'000; now.b += now.a)
            for (int i = 0; i < 2; ++i)
            {
                now.c = now.b * (init.c / now.b + i);
                if (now.c < now.b)
                    continue;
                if (dist(init, ans) > dist(init, now))
                    ans = now;
            }
    cout << dist(ans, init) << '\n';
    cout << ans.a << ' ' << ans.b << ' ' << ans.c << '\n';
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
