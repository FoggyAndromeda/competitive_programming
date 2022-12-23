n = int(input())

def f(x):
    res = 1
    for i in range(1, x + 1):
        res *= i
    return res

ans = 0
for i in range(2, n + 1):
    ans += f(n) // f(n - i)

print(ans)