
s = int(input())

ans = (s, 1)

for n in range(1, 50000):
    la = 1
    ra = 10**9

    while ra - la > 1:
        ma = (ra + la) >> 1

        nows = ((2 * ma + n - 1) * n) >> 1

        if (nows > s):
            ra = ma
        else:
            la = ma
    
    sl = ((2 * la + n - 1) * n) >> 1
    sr = ((2 * ra + n - 1) * n) >> 1

    if (sl == s):
        ans = (la, n)
    if (sr == s):
        ans = (ra, n)

print(*ans)
    
