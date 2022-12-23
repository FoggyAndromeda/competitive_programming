#include <bits\stdc++.h>

using namespace std;

int main()
{
    char c;
    string result(80, ' ');
    int now_pos = 0;
    while (scanf("%c", &c) != EOF)
    {
        if (c == '\n' || c == '\r')
            continue;
        if (c == '<')
        {
            now_pos = max(now_pos - 1, 0);
            continue;
        }
        if (c == '>')
        {
            if (now_pos == 79)
                now_pos = 0;
            else
                ++now_pos;
            continue;
        }
        result[now_pos] = c;
        if (now_pos == 79)
            now_pos = 0;
        else
            ++now_pos;
    }
    cout << result;
}