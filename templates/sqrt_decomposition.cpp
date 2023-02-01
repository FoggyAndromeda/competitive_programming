#include <bits/stdc++.h>

using namespace std;

template <class T = int>
class sqrt_decomp
{
private:
    vector<T> d;
    vector<T> orig;
    int n, sq;

    function<T(T, T)> f = [](T a, T b)
    {
        return a + b;
    };

public:
    sqrt_decomp(vector<T> &a)
    {
        n = a.size();
        sq = sqrt(n) + 1;
        orig = a;
        d.assign(sq, 0);
        for (int i = 0; i < n; ++i)
            d[i / sq] = f(d[i / sq], a[i]);
    }

    T rq(int l, int r)
    {
        T res = 0;
        int lb = l / sq, rb = r / sq;
        if (lb == rb)
        {
            for (int i = l; i <= r; ++i)
                res = f(res, orig[i]);
        }
        else
        {
            int e = (lb + 1) * sq - 1;
            for (int i = l; i <= e; ++i)
                res = f(res, orig[i]);
            for (int i = lb + 1; i < rb; ++i)
                res = f(res, d[i]);
            for (int i = rb * sq; i <= r; ++i)
                res = f(res, orig[i]);
        }
        return res;
    }
};

int main()
{
}