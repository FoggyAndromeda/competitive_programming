#include <bits\stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int ans = (n == 1);
    for (int a = 0; a <= 9; ++a)
        for (int b = 0; b <= 9; ++b)
            for (int c = 0; c <= 9; ++c)
                for (int d = 0; d <= 9; ++d)
                    for (int e = 0; e <= 9; ++e)
                        for (int f = 0; f <= 9; ++f)
                            for (int g = 0; g <= 9; ++g)
                                for (int h = 0; h <= 9; ++h)
                                {
                                    int now = n - (a + b + c + d + e + f + g + h);
                                    if (now >= 0 && now <= 9)
                                        ++ans;
                                }
    cout << ans << '\n';
}