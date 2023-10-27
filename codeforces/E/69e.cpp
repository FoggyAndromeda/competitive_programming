#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, k;
    cin >> n >> k;
    map<int, int> cnt;
    set<int> one_time;
    list<int> q;
    for (int i = 0; i < k; ++i)
    {
        int a;
        cin >> a;
        ++cnt[a];
        if (cnt[a] == 1)
            one_time.insert(a);
        else if (cnt[a] == 2)
            one_time.erase(a);
        q.push_back(a);
    }
    if (one_time.empty())
        cout << "Nothing\n";
    else
        cout << *one_time.rbegin() << '\n';
    for (int i = k; i < n; ++i)
    {
        --cnt[q.front()];
        if (cnt[q.front()] == 1)
            one_time.insert(q.front());
        if (cnt[q.front()] == 0)
            one_time.erase(q.front());
        q.pop_front();

        int a;
        cin >> a;

        ++cnt[a];
        if (cnt[a] == 1)
            one_time.insert(a);
        else if (cnt[a] == 2)
            one_time.erase(a);
        q.push_back(a);

        if (one_time.empty())
            cout << "Nothing\n";
        else
            cout << *one_time.rbegin() << '\n';
    }
}
