template <class T, class Func>
class segtree
{
private:
    vector<T> t;
    int n;
    Func f;

    void build(int v, int l, int r, const vector<T> &a)
    {
        if (l == r)
        {
            t[v] = a[l];
            return;
        }
        int m = (l + r) >> 1;
        build(2 * v, l, m, a);
        build(2 * v + 1, m + 1, r, a);
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }

public:
    segtree(const vector<T> &a)
    {
        n = a.size();
        t.assign(4 * n, f.neutral);
        build(1, 0, n - 1, a);
    }

    segtree(int k = 100'001)
    {
        n = k;
        t.assign(4 * n, f.neutral);
    }

    void add(int i, T d, int v = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l == r)
        {
            t[v] += d;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m)
            add(i, d, 2 * v, l, m);
        else
            add(i, d, 2 * v + 1, m + 1, r);
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }

    void upd(int i, T a, int v = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (l > r)
            return;
        if (l == r && l == i)
        {
            t[v] = a;
            return;
        }
        int m = (l + r) >> 1;
        if (i <= m)
            upd(i, a, 2 * v, l, m);
        else
            upd(i, a, 2 * v + 1, m + 1, r);
        t[v] = f(t[2 * v], t[2 * v + 1]);
    }

    T rq(int ql, int qr, int v = 1, int l = 0, int r = -1)
    {
        if (r == -1)
            r = n - 1;
        if (ql > qr)
            return f.neutral;
        if (ql == l && qr == r)
            return t[v];
        int m = (l + r) >> 1;

        if (qr <= m)
            return rq(ql, qr, 2 * v, l, m);
        if (m + 1 <= ql)
            return rq(ql, qr, 2 * v + 1, m + 1, r);

        return f(rq(ql, m, 2 * v, l, m), rq(m + 1, qr, 2 * v + 1, m + 1, r));
    }
};
