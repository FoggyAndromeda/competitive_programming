#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    vector<int> init_counter(10, 0);
    for (int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        ++init_counter[a];
    }
    cout << "- 0" << endl;
    int mimic_type = -1;
    while (1)
    {
        vector<int> a(n), counter(10, 0);
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
            ++counter[a[i]];
            if (counter[a[i]] > init_counter[a[i]])
                mimic_type = a[i];
        }
        if (mimic_type != -1)
        {
            cout << "- " << n - counter[mimic_type] << ' ';
            int new_n = n;
            for (int i = 0; i < n; ++i)
                if (a[i] != mimic_type)
                {
                    cout << i + 1 << ' ';
                    --new_n;
                }
            cout << endl;
            n = new_n;
            break;
        }
        else
            cout << "- 0" << endl;
    }
    while (1)
    {
        int ans = -1;
        for (int i = 0; i < n; ++i)
        {
            int a;
            cin >> a;
            if (a != mimic_type)
                ans = i + 1;
        }
        if (ans != -1)
        {
            cout << "! " << ans << endl;
            break;
        }
        else
            cout << "- 0" << endl;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t-- > 0)
        solve();
}