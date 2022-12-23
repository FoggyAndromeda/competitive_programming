n = int(input())

vis = set()

ans = 0

for i in range(n):
    s = input()
    if s in vis:
        ans += 1
    else:
        vis.add(s)

print(ans)