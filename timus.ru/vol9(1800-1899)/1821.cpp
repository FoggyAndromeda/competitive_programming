#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<tuple<int, int, string>> cnt;
    int now_start = 0, min_time = 0x7fffffff;
    for (int i = 0; i < n; ++i)
    {
        char s[21];
        int min, sec, dec;
        scanf("%s %d:%d.%d", &s, &min, &sec, &dec);
        int now_time = min * 600 + sec * 10 + dec;
        cnt.push_back({now_time + now_start, now_time, s});
        now_start += 300;
    }

    sort(cnt.begin(), cnt.end());
    int now_min = 0x7fffffff;
    vector<string> ans;
    ans.reserve(n);

    for (auto &[finish_time, now_time, name] : cnt)
    {
        if (now_time < now_min)
        {
            now_min = now_time;
            ans.push_back(name);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << '\n';
    for (string &s : ans)
        cout << s << '\n';
}