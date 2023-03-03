#include <bits/stdc++.h>

using namespace std;

int main()
{
    int m, d1, d2;
    cin >> m >> d1 >> d2;
    // 1 / (m * d1) * k * d2 = 1
    // k = ceil(m * d1 / d2)
    // ans: k k k k ... d2 - 1 times
    int k = ceil(float(m) * float(d1) / float(d2));
    int counter = 0;
    for (int i = 0; i < d2; ++i)
    {
        if (m * d1 - counter > k)
            cout << k << ' ';
        else
            cout << m * d1 - counter << ' ';
        counter = min(counter + k, m * d1);
    }
}