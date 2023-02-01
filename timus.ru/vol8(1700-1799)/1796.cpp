#include <bits/stdc++.h>

using namespace std;

int main()
{
    const vector<int> values = {10, 50, 100, 500, 1000, 5000};
    vector<int> prices;
    for (int i = 0; i < values.size(); ++i)
    {
        int now;
        cin >> now;
        for (int j = 0; j < now; ++j)
            prices.push_back(values[i]);
    }
    int price_one;
    cin >> price_one;
    int sum = 0;
    for (int &i : prices)
        sum += i;
    int less_sum = sum - prices[0];

    int ans = sum / price_one - less_sum / price_one;
    cout << ans << '\n';
    for (int i = less_sum / price_one + 1; i <= sum / price_one; ++i)
        cout << i << ' ';
}