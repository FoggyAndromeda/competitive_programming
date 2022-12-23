#include <bits\stdc++.h>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    vector<int> counter(30, 0);
    for (int i = 0; i < n; ++i)
        ++counter[s[i] - 'a'];
    char ans = 'a';
    for (char i = 0; i < counter.size(); ++i)
    {
        if (counter[i] > counter[ans - 'a'])
            ans = 'a' + i;
    }
    cout << ans << '\n';
}