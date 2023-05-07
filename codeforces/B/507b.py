r, x0, y0, x, y = map(int, input().split())

x -= x0
y -= y0

dist = (x * x + y * y) ** 0.5

ans = int(dist / (2 * r))

if dist - 2 * r * ans > 0:
    ans += 1

print(ans)