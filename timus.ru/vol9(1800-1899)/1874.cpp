#include <bits/stdc++.h>

using namespace std;

/*
f(a, b) = l1 * sin(a) * l2 * sin(b) + l1^2 sin(2a) / 4 + l2^2 * sin(2b) / 4 -> max

a, b in (0, pi / 2]

df/da = l1 * l2 * cos(a) * sin(b) + l1^2 cos(2a) / 2

df/db = l1 * l2 * sin(a) * cos(b) + l2^2 cos(2b) / 2



*/

const int num_of_iterations = 100;

int main()
{
    double l1, l2;
    cin >> l1 >> l2;
    double a = 0, b = 0;
    double delta = 3.14159265358979323846264338327;
    delta *= 0.5;
    for (int i = 0; i < num_of_iterations; ++i)
    {
        double da = l1 * l2 * cos(a) * sin(b) + l1 * l1 * cos(2 * a) * 0.5;
        double db = l1 * l2 * cos(b) * sin(a) + l2 * l2 * cos(2 * b) * 0.5;
        if (da < 0)
            a -= delta;
        else
            a += delta;
        if (db < 0)
            b -= delta;
        else
            b += delta;
        delta *= 0.5;
    }
    cout << fixed << setprecision(9);
    cout << l1 * sin(a) * l2 * sin(b) + 0.25 * (l1 * l1 * sin(2 * a) + l2 * l2 * sin(2 * b));
}