#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    map<string, string> users;
    set<string> logined;
    for (int i = 0; i < n; ++i)
    {
        string req;
        cin >> req;
        if (req == "register")
        {
            string name, password;
            cin >> name >> password;
            if (users.find(name) != users.end())
            {
                cout << "fail: user already exists\n";
            }
            else
            {
                cout << "success: new user added\n";
                users[name] = password;
            }
        }
        if (req == "login")
        {
            string name, password;
            cin >> name >> password;
            if (users.find(name) == users.end())
            {
                cout << "fail: no such user\n";
            }
            else if (users[name] != password)
            {
                cout << "fail: incorrect password\n";
            }
            else if (logined.find(name) != logined.end())
            {
                cout << "fail: already logged in\n";
            }
            else
            {
                cout << "success: user logged in\n";
                logined.insert(name);
            }
        }
        if (req == "logout")
        {
            string name;
            cin >> name;
            if (users.find(name) == users.end())
            {
                cout << "fail: no such user\n";
            }
            else if (logined.find(name) == logined.end())
            {
                cout << "fail: already logged out\n";
            }
            else
            {
                cout << "success: user logged out\n";
                logined.erase(name);
            }
        }
    }
}