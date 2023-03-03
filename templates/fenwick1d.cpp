#include <bits/stdc++.h>

using namespace std;

template <class T>
class FenwickTree
{
private:
    vector<T> t;
    int n;

    T pref(int i)
    {
        T res = 0;
        for (++i; i > 0; i -= i & -i)
            res = res + t[i];
        return res;
    }

public:
    FenwickTree(vector<T> &a)
    {
        n = a.size() + 1;
        t.assign(n, 0);
        for (int i = 0; i < a.size(); ++i)
            upd(i, a[i]);
    }

    FenwickTree(int l)
    {
        n = l + 1;
        t.assign(n, 0);
    }

    T rq(int l, int r)
    {
        if (l == 0)
            return pref(r);
        return pref(r) - pref(l - 1);
    }

    void upd(int i, T nw)
    {
        int now = rq(i, i);
        for (++i; i < n; i += i & -i)
        {
            t[i] -= now;
            t[i] += nw;
        }
    }

    void add(int i, T d)
    {
        for (++i; i < n; i += i & -i)
            t[i] += d;
    }

    T lowerbound(T v)
    {
        T sum = 0;
        int pos = 0, lgn = __lg(n);
        for (int i = lgn; i >= 0; --i)
        {
            if (pos + (1 << i) < n - 1 && sum + t[pos + (1 << i)] < v)
            {
                sum += t[pos + (1 << i)];
                pos += (1 << i);
            }
        }
        return pos;
    }

    T operator()(int l, int r)
    {
        return rq(l, r);
    }

    T operator()(int r)
    {
        return pref(r);
    }

    T operator[](int i)
    {
        return rq(i, i);
    }
};

int main()
{
}