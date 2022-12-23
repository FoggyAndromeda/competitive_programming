n = int(input())

def f(x):
    ans = 1
    for i in range(1, x + 1):
        ans *= i
    return ans

def cnk(n, k):
    return f(n) // f(k) // f(n - k)

a = map(lambda x: int(x) - 1, input().split())

counter = [0] * 3

for i in a:
    counter[i] += 1

ans = cnk(n, counter[0]) * cnk(n - counter[0], counter[1])

if (ans >= 6):
    print("Yes")
else:
    print("No")