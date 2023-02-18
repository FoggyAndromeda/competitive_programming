def dist(a, b, c, d):
    return ((c - a) ** 2 + (d - b) ** 2) ** 0.5

ax, ay, bx, by = map(int, input().split())
x0, y0, r = map(int, input().split())

a = dist(x0, y0, ax, ay)
b = dist(x0, y0, bx, by)
c = dist(ax, ay, bx, by)

p = (a + b + c) / 2
s = (p * (p - a) * (p - b) * (p - c)) ** 0.5
h = 2 * s / c

print("%.2f" % max(0, min(h, a, b) - r))
print("%.2f" % max(0, max(a, b) - r))