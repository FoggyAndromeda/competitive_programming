n, k = map(int, input().split())

if n in [2, 3]:
    print(0)
else:
    print(max(n - k - 2, k - 3))
