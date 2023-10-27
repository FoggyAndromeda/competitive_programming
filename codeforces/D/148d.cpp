#include <bits/stdc++.h>

using namespace std;

int maxn = 1e3 + 1;

vector<vector<double>> memp(maxn, vector<double>(maxn, -1));
vector<vector<double>> memd(maxn, vector<double>(maxn, -1));

double prob_princess_win(int w, int b);
double prob_dragon_win(int w, int b);

double prob_princess_win(int w, int b)
{
    if (w + b == 0)
        return 0;
    if (b == 0)
        return 1;
    if (w == 0)
        return 0;
    if (memp[w][b] != -1)
        return memp[w][b];
    double dw = w;
    double db = b;
    return memp[w][b] = (dw + db * (1 - prob_dragon_win(w, b - 1))) / (dw + db);
}

double prob_dragon_win(int w, int b)
{
    if (w + b == 0 || w + b == 2 || b * w == 0)
        return 1;
    if (memd[w][b] != -1)
        return memd[w][b];
    double dw = w;
    double db = b;
    double res = dw / (dw + db);

    if (b > 1)
        res += db / (dw + db) * (dw / (dw + db - 1) * (1 - prob_princess_win(w - 1, b - 1)) + (db - 1) / (dw + db - 1) * (1 - prob_princess_win(w, b - 2)));

    return memd[w][b] = res;
}

int main()
{
    int w, b;
    cin >> w >> b;
    cout << fixed << setprecision(10) << prob_princess_win(w, b) << '\n';
}