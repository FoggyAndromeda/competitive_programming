from math import ceil, sqrt

r = int(input())

ans = 0

for i in range(r + 1):
    ans += ceil(sqrt(r * r - i * i))

print(4 * ans)