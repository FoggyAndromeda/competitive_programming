#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    i64 n;
    cin >> n;
    i64 possum = 0, negsum = 0;
    priority_queue<i64, vector<i64>, greater<i64>> neg;
    i64 ans = n;
    for (i64 i = 0; i < n; ++i)
    {
        i64 now;
        cin >> now;
        if (now > 0)
            possum += now;
        else
        {
            negsum += now;
            neg.push(now);
            while (possum < abs(negsum))
            {
                negsum -= neg.top();
                neg.pop();
                --ans;
            }
        }
    }
    cout << ans << '\n';
}