#include <bits\stdc++.h>

using namespace std;

using ui64 = uint64_t;

int main()
{
    ui64 n;
    vector<ui64> nums;
    while (scanf("%llu", &n) != EOF)
    {
        nums.push_back(n);
    }
    cout.precision(4);
    cout.fixed;
    for (int i = nums.size() - 1; i > -1; --i)
    {
        cout << sqrt(double(nums[i])) << '\n';
    }
}