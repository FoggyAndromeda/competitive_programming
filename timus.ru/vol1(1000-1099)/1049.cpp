#include <bits\stdc++.h>

using namespace std;

int main()
{
    vector<int> count(10000, 1);
    for (int i = 0; i < 10; ++i)
    {
        int now;
        cin >> now;
        int now_del = 2;
        while (now > 1)
        {
            while (now % now_del == 0)
            {
                ++count[now_del];
                now /= now_del;
            }
            ++now_del;
        }
    }
    int ans = 1;
    for (int i = 0; i < count.size(); ++i)
    {
        ans = (ans * count[i]) % 10;
    }
    cout << ans % 10 << '\n';
}