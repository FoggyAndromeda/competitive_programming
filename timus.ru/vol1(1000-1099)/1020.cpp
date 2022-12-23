#include <bits\stdc++.h>

using namespace std;

double distance(double x1, double y1, double x2, double y2)
{
    return sqrtl((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

const double pi = 3.14159265358979323846;

int main()
{
    int n;
    double r;
    cin >> n >> r;
    double dist = 2 * pi * r;
    double first_x, first_y;
    cin >> first_x >> first_y;
    double prev_x = first_x, prev_y = first_y;
    double now_x = first_x, now_y = first_y;
    for (int i = 1; i < n; ++i)
    {
        cin >> now_x >> now_y;
        dist += distance(now_x, now_y, prev_x, prev_y);
        prev_x = now_x;
        prev_y = now_y;
    }
    dist += distance(now_x, now_y, first_x, first_y);
    printf("%.2lf\n", dist);
}