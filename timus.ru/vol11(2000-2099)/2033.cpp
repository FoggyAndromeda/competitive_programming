#include <bits/stdc++.h>

using namespace std;

int main()
{
    string ans_name;
    map<string, pair<int, int>> counter;
    for (int i = 0; i < 6; ++i)
    {
        string name, device;
        int price;
        cin >> name >> device >> price;
        if (counter.count(device))
        {
            ++counter[device].first;
            counter[device].second = min(counter[device].second, price);
        }
        else
        {
            counter[device] = {1, price};
        }
        ans_name = device;
    }
    for (auto [name, info] : counter)
    {
        if (info.first > counter[ans_name].first)
            ans_name = name;
        if (info.first == counter[ans_name].first && info.second < counter[ans_name].second)
            ans_name = name;
    }
    cout << ans_name << '\n';
}