#include <bits/stdc++.h>

using namespace std;

#define int int64_t

vector<int> prec;

void precalc()
{
    for (int p1 = 0, t1 = 1; p1 < 18; ++p1, t1 *= 10)
        for (int p2 = 0, t2 = 1; p2 < p1; ++p2, t2 *= 10)
            for (int p3 = 0, t3 = 1; p3 < p2; ++p3, t3 *= 10)
                for (int i = 0; i < 10; ++i)
                    for (int j = 0; j < 10; ++j)
                        for (int k = 0; k < 10; ++k)
                            prec.push_back(i * t1 + j * t2 + k * t3);
    prec.push_back(1'000'000'000'000'000'000);
    sort(prec.begin(), prec.end());
    prec.erase(unique(prec.begin(), prec.end()), prec.end());
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    precalc();

    int t;
    cin >> t;
    while (t-- > 0)
    {
        int l, r;
        cin >> l >> r;

        int ll = -1, rl = prec.size();
        while (rl - ll > 1)
        {
            int m = (rl + ll) >> 1;
            if (prec[m] < l)
                ll = m;
            else
                rl = m;
        }

        int lr = -1, rr = prec.size();
        while (rr - lr > 1)
        {
            int m = (rr + lr) >> 1;
            if (prec[m] <= r)
                lr = m;
            else
                rr = m;
        }

        cout << lr - rl + 1 << '\n';
    }
}