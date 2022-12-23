#include <bits\stdc++.h>

using namespace std;

int main()
{
    string init;
    cin >> init;
    stack<char> s;
    for (char c : init)
    {
        if (!s.empty() && c == s.top())
        {
            s.pop();
        }
        else
        {
            s.push(c);
        }
    }
    string ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    reverse(ans.begin(), ans.end());
    cout << ans << '\n';
}