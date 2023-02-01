n, k = map(int, input().split())

a = list(map(int, input().split()))

ans = a[0]

for i in range(1, k):
    ans = max(0, ans + a[i] - n)

print(ans)