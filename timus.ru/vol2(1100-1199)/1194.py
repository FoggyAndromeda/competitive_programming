import sys

n, k = map(int, input().split())

for line in sys.stdin:
    pass

print(n * (n - 1) // 2 - k)