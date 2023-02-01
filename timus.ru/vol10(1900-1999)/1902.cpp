#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout << fixed << setprecision(6);
    int n, t, t0;
    cin >> n >> t >> t0;
    vector<float> ans;
    for (int i = 0; i < n; ++i)
    {
        int ti;
        cin >> ti;
        float a = float(t + t0 + ti) / 2.f;
        if (a < t0 || a > t0 + t)
            continue;
        ans.push_back(a);
    }
    for (float f : ans)
        cout << f << '\n';
}