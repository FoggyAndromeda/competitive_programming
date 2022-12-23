#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    int k;
    cin >> k;
    vector<pair<int, int>> diags(k);
    for (int i = 0; i < k; ++i)
    {
        cin >> diags[i].first >> diags[i].second;
    }
    sort(diags.begin(), diags.end());
    vector<int> passed_diags(k, 1);
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            if (diags[j].second < diags[i].second && diags[j].first < diags[i].first)
            {
                passed_diags[i] = max(passed_diags[i], passed_diags[j] + 1);
            }
        }
    }
    int max_diags = 0;
    for (int i = 0; i < k; ++i)
        max_diags = max(max_diags, passed_diags[i]);
    int straight_count = m + n - 2 * max_diags;
    double ans = (sqrtl(2) * max_diags + straight_count) * 100;
    cout << floor(ans + 0.5) << '\n';
}