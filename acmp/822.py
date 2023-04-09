x1, y1, x2, y2, x3, y3 = map(int, input().split())

x12 = x2 - x1
y12 = y2 - y1

x13 = x3 - x1
y13 = y3 - y1

print(abs(x12 * y13 - x13 * y12) / 2)