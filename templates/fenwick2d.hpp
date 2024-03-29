template <class T = int>
class FenwickTree
{
private:
    vector<vector<T>> t;
    int n, m;

    T pref(int r, int c)
    {
        T res = 0;
        for (int i = r + 1; i > 0; i -= i & -i)
            for (int j = c + 1; j > 0; j -= j & -j)
                res = res + t[i][j];
        return res;
    }

public:
    FenwickTree(vector<vector<T>> &a)
    {
        n = a.size() + 1;
        m = a[0].size() + 1;
        t.assign(n, vector<T>(m, 0));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                upd(i, j, a[i][j]);
    }

    FenwickTree(int r, int c)
    {
        n = r + 1;
        m = c + 1;
        t.assign(n, vector<T>(m, 0));
    }

    T rq(int r1, int c1, int r2, int c2)
    {
        return pref(r2, c2) + pref(r1 - 1, c1 - 1) - pref(r1 - 1, c2) - pref(r2, c1 - 1);
    }

    void upd(int r, int c, T nw)
    {
        int now = rq(r, c, r, c);
        for (int i = r + 1; i < n; i += i & -i)
            for (int j = c + 1; j < m; j += j & -j)
            {
                t[i][j] -= now;
                t[i][j] += nw;
            }
    }

    void add(int r, int c, T d)
    {
        for (int i = r + 1; i < n; i += i & -i)
            for (int j = c + 1; j < m; j += j & -j)
                t[i][j] += d;
    }
};
