#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int &i : a)
        cin >> i;
    vector<int> counter(n, 0);
    int now_ans = 0;
    for (int i = 1; i < n; ++i)
    {
        ++counter[now_ans];
        ++counter[i];
        if (a[now_ans] > a[i])
            now_ans = i;
    }
    cout << max_element(counter.begin(), counter.end()) - counter.begin() + 1 << '\n';
}