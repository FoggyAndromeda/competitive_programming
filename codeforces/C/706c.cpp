#include <bits/stdc++.h>

using namespace std;
#define int int64_t

const int INF = 2e18;

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> c(n);
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    string prev;
    cin >> prev;
    string reverse_prev = prev;
    reverse(reverse_prev.begin(), reverse_prev.end());

    pair<int, int> now_wasted{0, c[0]};

    for (int i = 1; i < n; ++i)
    {
        string now;
        cin >> now;
        pair<int, int> now_possible{INF, INF};
        if (now >= prev)
            now_possible.first = now_wasted.first;
        if (now >= reverse_prev)
            now_possible.first = min(now_possible.first, now_wasted.second);
        reverse(now.begin(), now.end());
        if (now >= prev)
            now_possible.second = now_wasted.first + c[i];
        if (now >= reverse_prev)
            now_possible.second = min(now_possible.second, now_wasted.second + c[i]);
        reverse_prev = now;
        reverse(now.begin(), now.end());
        prev = now;
        now_wasted = now_possible;
    }
    if (now_wasted.first >= INF && now_wasted.second >= INF)
        cout << "-1\n";
    else
        cout << min(now_wasted.first, now_wasted.second) << '\n';
}