r, g, b = map(int, input().split())

ans = r // 3 + g // 3 + b // 3

if min(r, g, b) > 0:
    ans = max(ans, 1 + (r - 1) // 3 + (g - 1) // 3 + (b - 1) // 3)
if min(r, g, b) > 1:
    ans = max(ans, 2 + (r - 2) // 3 + (g - 2) // 3 + (b - 2) // 3)

print(ans)
