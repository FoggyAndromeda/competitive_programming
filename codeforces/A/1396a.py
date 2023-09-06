n = int(input())

a = list(map(int, input().split()))

print(1, 1)
print(-a[0])

if n == 1:
    print("1 1\n0\n1 1\n0")
    exit(0)

print(1, n)
print(0, end=' ')
print(*[-a[i] * n for i in range(1, n)])

print(2, n)
print(*[a[i] * (n - 1) for i in range(1, n)])
