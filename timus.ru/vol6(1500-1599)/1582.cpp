#include <bits/stdc++.h>

using namespace std;

int main()
{
    float k1, k2, k3;
    cin >> k1 >> k2 >> k3;
    cout << int(1000.f * k1 * k2 * k3 / (k1 * k2 + k2 * k3 + k1 * k3) + 0.5);
}