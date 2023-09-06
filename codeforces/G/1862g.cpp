#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")

#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    multiset<int> elements;
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        elements.insert(a[i]);
    }
    multiset<int> deltas;
    auto prvi = elements.begin();
    auto nxti = elements.begin();
    nxti++;
    for (; nxti != elements.end(); prvi++, nxti++)
    {
        deltas.insert((*nxti) - (*prvi));
    }

    int q;
    cin >> q;
    while (q-- > 0)
    {
        int ind, x;
        cin >> ind >> x;
        --ind;
        if (n == 1)
        {
            cout << x << ' ';
            continue;
        }

        auto it = elements.find(a[ind]);
        auto prv = prev(it);
        auto nxt = next(it);

        if (it == elements.begin())
            deltas.erase(deltas.find((*nxt) - (*it)));
        else if (it == prev(elements.end()))
            deltas.erase(deltas.find((*it) - (*prv)));
        else
        {
            deltas.erase(deltas.find((*nxt) - (*it)));
            deltas.erase(deltas.find((*it) - (*prv)));
            deltas.insert((*nxt) - (*prv));
        }

        elements.erase(it);
        a[ind] = x;
        elements.insert(x);

        it = elements.find(a[ind]);
        prv = prev(it);
        nxt = next(it);

        if (it == elements.begin())
            deltas.insert((*nxt) - (*it));
        else if (it == prev(elements.end()))
            deltas.insert((*it) - (*prv));
        else
        {
            deltas.insert((*nxt) - (*it));
            deltas.insert((*it) - (*prv));
            deltas.erase(deltas.find((*nxt) - (*prv)));
        }
        cout << (*elements.rbegin()) + (*deltas.rbegin()) << ' ';
    }
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