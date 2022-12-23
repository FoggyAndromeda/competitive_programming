#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> reminders(n);
    for (int i = 0; i < n; ++i)
    {
        int now;
        cin >> now;
        reminders[now % n].push_back(now);
    }
}