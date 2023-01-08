#include <bits/stdc++.h>

using namespace std;

template <class T>
struct heap
{
    vector<T> h;

    void push(const T a)
    {
        h.push_back(a);
        push_heap(h.begin(), h.end(), a);
    }

    T top()
    {
        return h[0];
    }

    void pop()
    {
        pop_heap(h.begin(), h.end());
        h.pop_back();
    }
};

int main()
{
}