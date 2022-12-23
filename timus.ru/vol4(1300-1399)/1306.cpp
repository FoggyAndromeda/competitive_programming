#include <bits/stdc++.h>

using namespace std;
using uint = uint32_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<uint> pq;
    pq.reserve(125'002);
    uint now;
    int i = 0;
    for (; i < n / 2 + 1; ++i)
    {
        cin >> now;
        pq.push_back(now);
        push_heap(pq.begin(), pq.end());
    }
    for (; i < n; ++i)
    {
        cin >> now;
        pq.push_back(now);
        push_heap(pq.begin(), pq.end());
        pop_heap(pq.begin(), pq.end());
        pq.pop_back();
    }
    if (n & 1)
        cout << pq[0];
    else
    {
        uint ans = pq[0];
        pop_heap(pq.begin(), pq.end());
        pq.pop_back();
        ans += pq[0];
        cout << ans / 2;
        if (ans % 2 == 1)
            cout << ".5";
    }
    cout << '\n';
    cout.flush();
}