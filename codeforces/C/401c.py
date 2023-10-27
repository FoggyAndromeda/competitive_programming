k0, k1 = map(int, input().split())

possible = True
print0 = False
print11 = False

cnt110 = k1 - k0
cnt10 = k0 - cnt110

if cnt110 < 0 or cnt10 < 0:
    print0 = True
    k0 -= 1
    cnt110 = k1 - k0
    cnt10 = k0 - cnt110
    if cnt110 < 0 or cnt10 < 0:
        print0 = False
        print11 = True
        k0 += 1
        k1 -= 2
        cnt110 = k1 - k0
        cnt10 = k0 - cnt110
        if cnt110 < 0 or cnt10 < 0:
            possible = False

if not possible:
    print(-1)
else:
    if print0:
        print(0, end='')
    print("110" * cnt110, "10" * cnt10, sep='', end='')
    if print11:
        print("11")
