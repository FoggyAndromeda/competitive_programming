#include <bits/stdc++.h>

using namespace std;

template <class T = int>
class sparse_table
{
private:
    vector<vector<T>> t;
    int n, lgn;

    function<T(T, T)> f = [](T a, T b)
    {
        return min(a, b);
    };

public:
    sparse_table(vector<T> &a)
    {
        n = a.size();
        lgn = log2(n) + 1;
        t.assign(lgn, vector<T>(n, 0));

        for (int i = 0; i < n; ++i)
            t[0][i] = a[i];

        for (int l = 0; l < lgn - 1; ++l)
            for (int i = 0; i + (1 << l) <= n; ++i) // 1?
                t[l + 1][i] = f(t[l][i], t[l][i + (1 << l)]);
    }

    T rq(int l, int r)
    {
        int lgd = __lg(r - l);
        return f(t[lgd][l], t[lgd][r - (1 << lgd)]);
    }
};

int main()
{
}