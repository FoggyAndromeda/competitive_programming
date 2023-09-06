import sys

inp = sys.stdin.readlines()

for i in range(1, len(inp)):
    x1, y1, x2, y2 = map(int, inp[i].split())
    dx = x2 - x1 + 1
    dy = y2 - y1 + 1
    print((dx - 1) * (dy - 1) + 1)
