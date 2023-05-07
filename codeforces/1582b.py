t = int(input())

for _ in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    print(a.count(1) * (1 << a.count(0)))
