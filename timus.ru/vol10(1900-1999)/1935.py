n = int(input())

a = sorted(list(map(int, input().split())))

ans = a[0] + a[-1]

for i in range(n - 1):
    ans += max(a[i], a[i + 1])

print(ans)