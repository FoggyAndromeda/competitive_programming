#include <bits\stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i)
        cin >> nums[i];
    sort(nums.begin(), nums.end());
    string s;
    cin >> s;
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int now;
        cin >> now;
        cout << nums[now - 1] << '\n';
    }
}