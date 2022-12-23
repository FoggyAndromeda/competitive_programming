#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<int> teacher;
    for (int i = 0; i < n; ++i)
    {
        int now;
        cin >> now;
        teacher.insert(now);
    }
    int m;
    cin >> m;
    int ans = 0;
    for (int i = 0; i < m; ++i)
    {
        int now;
        cin >> now;
        if (teacher.find(now) != teacher.end())
            ++ans;
    }
    cout << ans << '\n';
}