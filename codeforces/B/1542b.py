def solve():
    n, a, b = map(int, input().split())
    ans = False
    nowpow = 1
    for i in range(40):
        if nowpow > n:
            break
        if nowpow % b == n % b:
            ans = True
            break
        nowpow *= a
    if ans: print("YES")
    else: print("NO")

t = int(input())

for _ in range(t):
    solve()