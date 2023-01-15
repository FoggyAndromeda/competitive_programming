#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> result;
    while (n > 1)
    {
        int h = n / 2;
        result.push_back(h);
        n -= h;
    }
    cout << result.size() << '\n';
    for (auto elem : result)
    {
        cout << elem << ' ';
    }
}