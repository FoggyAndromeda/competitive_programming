#include <bits/stdc++.h>

using namespace std;

/*
2!
3!
4! = 1 * 2 * 3 * 4 = 2! 2! 3!
5!
6! = 1 * 2 * 3 * 4 * 5 * 2 * 3 = 5! 3!
7!
8! = 7! 2! 2! 2!
9! = 1 * 2 * 3 * 4 * 5 * 6 * 7 * 2 * 2 * 2 * 3 * 3 =  7! 3! 3! 2!
*/

int main()
{
    int n;
    cin >> n;
    vector<int> res;
    string s;
    cin >> s;
    for (char now : s)
    {
        switch (now)
        {
        case '4':
            res.push_back(2);
            res.push_back(2);
            res.push_back(3);
            break;
        case '6':
            res.push_back(5);
            res.push_back(3);
            break;
        case '8':
            res.push_back(7);
            res.push_back(2);
            res.push_back(2);
            res.push_back(2);
            break;
        case '9':
            res.push_back(7);
            res.push_back(3);
            res.push_back(3);
            res.push_back(2);
            break;

        default:
            if (now > '1')
                res.push_back(now - '0');
            break;
        }
    }
    sort(res.begin(), res.end(), greater<int>());
    for (auto elem : res)
        cout << elem;
    cout << '\n';
}