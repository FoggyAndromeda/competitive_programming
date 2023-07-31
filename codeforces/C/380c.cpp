#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int length, open, close;
};

class segtree
{
    vector<Point> t;
    int n;

    void build(int v, int l, int r, string &a)
    {
        if (l == r)
        {
            t[v].length = 0;
            t[v].open = a[l] == '(';
            t[v].close = a[l] == ')';
            return;
        }
        int m = (l + r) >> 1;
        build(2 * v, l, m, a);
        build(2 * v + 1, m + 1, r, a);
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }

    Point f(Point a, Point b)
    {
        Point result;
        result.length = a.length + b.length + 2 * min(a.open, b.close);
        result.open = a.open + a.length / 2 + b.open + b.length / 2 - result.length / 2;
        result.close = a.close + a.length / 2 + b.close + b.length / 2 - result.length / 2;
        return result;
    }

public:
    segtree(string &a)
    {
        n = a.size();
        t.assign(4 * n, Point());
        build(1, 0, n - 1, a);
    }

    Point rq(int ql, int qr, int v = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l > r)
            return Point{0, 0, 0};
        if (ql == l && qr == r)
            return t[v];
        int m = (l + r) >> 1;

        if (qr <= m)
            return rq(ql, qr, 2 * v, l, m);
        if (m + 1 <= ql)
            return rq(ql, qr, 2 * v + 1, m + 1, r);
        Point left = rq(ql, m, 2 * v, l, m);
        Point right = rq(m + 1, qr, 2 * v + 1, m + 1, r);
        return f(left, right);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    segtree st(s);
    int n;
    cin >> n;
    while (n-- > 0)
    {
        int l, r;
        cin >> l >> r;
        --l;
        --r;
        cout << st.rq(l, r).length << '\n';
    }
}