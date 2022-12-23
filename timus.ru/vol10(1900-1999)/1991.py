n, k = map(int, input().split())

a = list(map(int, input().split()))

left = 0
alive = 0

for i in range(n):
    if (a[i] > k):
        left += a[i] - k
    else:
        alive += k - a[i]

print(left, alive)