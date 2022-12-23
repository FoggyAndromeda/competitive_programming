#include <bits\stdc++.h>

using namespace std;

int main()
{
    vector<int> code;
    multiset<int> code_sorted;
    int num;
    while (scanf("%i", &num) != EOF)
    {
        code.push_back(num);
        code_sorted.insert(num);
    }
    reverse(code.begin(), code.end());
    int n = code.size() + 2;
    vector<vector<int>> tree(n);
    while (!code.empty())
    {
    }
}