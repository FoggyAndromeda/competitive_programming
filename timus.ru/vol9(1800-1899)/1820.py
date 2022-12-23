import math

n, k = map(int, input().split())

ans = 0

if n <= k:
    ans = 2
else:
    count = 2 * n

    while count > 0:
        count -= k
        ans += 1

print(ans)