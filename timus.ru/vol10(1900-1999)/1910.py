n = int(input())

a = list(map(int, input().split()))


maxs = 0
maxi = -1
for i in range(1, n - 1):
    s = a[i - 1] + a[i] + a[i + 1]
    if (s > maxs):
        maxs = s
        maxi = i + 1

print(maxs, maxi)
