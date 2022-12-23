#include <bits\stdc++.h>

using namespace std;

int main()
{
    int k;
    cin >> k;
    vector<int> nums;
    int a;
    cin >> a;
    while (a > -1)
    {
        nums.push_back(a);
        cin >> a;
    }
    int n = nums.size();
    vector<int> ans;
    for (int b = 0; b < n - k + 1; ++b)
    {
        int now_ans = -1;
        for (int i = 0; i < k; ++i)
        {
            now_ans = max(now_ans, nums[b + i]);
        }
        ans.push_back(now_ans);
    }
    for (int i : ans)
        cout << i << '\n';
}