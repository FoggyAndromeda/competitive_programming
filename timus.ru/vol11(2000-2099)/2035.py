x, y, c = map(int, input().split())

l = 0
r = x

while r - l > 1:
    mid = (r + l) >> 1
    if (c - mid < 0):
        r = mid
    if (c - mid > y):
        l = mid
    elif (c - mid >= 0 and c - mid <= y):
        print(mid, c - mid)
        break
else:
    if (c - r >= 0 and c - r <= y):
        print(r, c - r)
    elif (c - l >= 0 and c - l <= y):
        print(l, c - l)
    else:
        print("Impossible")