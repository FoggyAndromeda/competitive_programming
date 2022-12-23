from functools import reduce


n, m = map(int, input().split())

if (m > n // 2):
    m = n - m

c = reduce(lambda x, y: x * y, range(n - m + 1, n + 1)) // reduce(lambda x, y: x * y, range(2, m + 1))

if not(c & 1):
    res = 1
    while not(c & 1):
        c >>= 1
else:
    res = 0

now_div = 3

while (c > 1):
    if (c % now_div == 0):
        res += 1
    while (c % now_div == 0):
        c //= now_div
    now_div += 2

print(res)