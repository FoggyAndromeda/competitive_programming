t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = [n // k + (i < n % k) for i in range(k)]
    ans = 0
    for i in range(k - 1):
        ans += a[i] * sum(a[i + 1:])
    print(ans)