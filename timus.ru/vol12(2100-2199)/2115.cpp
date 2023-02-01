#pragma GCC optimze("Ofast")

#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> orig(n);
    vector<int> copy(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> orig[i];
        copy[i] = orig[i];
    }
    sort(copy.begin(), copy.end());
    list<int> repl;
    for (int i = 0; i < n; ++i)
        if (copy[i] != orig[i])
            repl.push_back(i);
    if (repl.size() > 2)
    {
        repl.clear();
        reverse(copy.begin(), copy.end());
        for (int i = 0; i < n; ++i)
            if (copy[i] != orig[i])
                repl.push_back(i);
    }
    if (repl.size() == 0)
    {
        cout << "Nothing to do here\n";
    }
    else if (repl.size() == 2)
    {
        cout << "YES\n";
        for (int elem : repl)
            cout << elem + 1 << ' ';
    }
    else
        cout << "No hope\n";
}