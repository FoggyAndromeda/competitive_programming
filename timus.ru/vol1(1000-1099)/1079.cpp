#include <bits\stdc++.h>

using namespace std;

const int max_size = 1e5;

int main()
{
    vector<int> nums(max_size);
    nums[0] = 0;
    nums[1] = 1;
    for (int i = 2; i < max_size; ++i)
    {
        if (i & 1)
        {
            nums[i] = nums[i / 2] + nums[i / 2 + 1];
        }
        else
            nums[i] = nums[i / 2];
    }
    vector<int> maximums(max_size);
    maximums[0] = nums[0];
    for (int i = 1; i < max_size; ++i)
        maximums[i] = max(maximums[i - 1], nums[i]);
    int n;
    cin >> n;
    while (n > 0)
    {
        cout << maximums[n] << '\n';
        cin >> n;
    }
}