k, n = map(int, input().split())

a = list(map(int, input().split()))

ans = 0
for i in range(n):
    ans += a[i]
    ans -= k
    ans = max(ans, 0)

print(ans)