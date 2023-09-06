#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n * n);
    for (int i = 0; i < n * n; ++i)
        cin >> a[i];

    sort(a.begin(), a.end());
    reverse(a.begin(), a.end());

    unordered_map<int, int> to_skip;
    vector<int> result;
    for (int i : a)
        if (to_skip[i] == 0)
        {
            for (int j : result)
                to_skip[__gcd(i, j)] += 2;
            result.push_back(i);
        }
        else
            --to_skip[i];
    for (auto elem : result)
        cout << elem << ' ';
}