#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> nums[i];
    }
    sort(nums.begin(), nums.end());
    int ans = 0;
    for (int i = 0; i < n / 2 + 1; ++i)
    {
        ans += nums[i] / 2 + 1;
    }
    cout << ans << '\n';
}