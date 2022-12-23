s = int(input())

la = 1
ra = 10 ** 600

while ra - la > 1:
    ma = (la + ra) >> 1
    if ma * (ma + 1) > 2 * s:
        ra = ma
    else:
        la = ma

if ra * (ra + 1) == 2 * s:
    print(ra)
else:
    print(la)