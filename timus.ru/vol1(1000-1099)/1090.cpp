#include <bits\stdc++.h>
#include <ext\pb_ds\assoc_container.hpp> // Общий файл.
#include <ext\pb_ds\tree_policy.hpp>     // Содержит класс tree_order_statistics_node_update

using namespace std;
using namespace __gnu_pbds;

template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = -1;
    int ans_count = -1;
    for (int i = 1; i <= k; ++i)
    {
        int now_count = 0;
        ordered_set<int> now_os;
        for (int j = 0; j < n; ++j)
        {
            int now;
            cin >> now;
            now = n - now;
            now_count += now_os.order_of_key(now);
            now_os.insert(now);
        }
        if (now_count > ans_count)
        {
            ans_count = now_count;
            ans = i;
        }
    }
    cout << ans << '\n';
}