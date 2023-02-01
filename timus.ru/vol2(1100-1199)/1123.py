s = input()

n = len(s)

if (n == 1):
    print(s)
    exit(0)

if n % 2 == 0:
    half_s = int(s[:n//2])
    sp_s = int(s[-1 : n//2 - 1 : -1])

    p10 = 10;

    if half_s % 10 == 0:
        half_s += 1
    else:
        while p10 <= 10 * half_s:
            if half_s % p10 == sp_s % p10:
                p10 *= 10
                continue
            if half_s % p10 > sp_s % p10:
                break
            if half_s % p10 < sp_s % p10:
                half_s += 1
                break

    print(half_s, end='')
    while half_s > 0:
        print(half_s % 10, end='')
        half_s //= 10
    print()
else:
    half_s = int(s[:n//2])
    mid = int(s[n // 2])
    sp_s = int(s[-1 : n//2: -1])

    p10 = 10;

    while p10 <= 10 * half_s:
        if half_s % p10 == sp_s % p10:
            p10 *= 10
            continue
        if half_s % p10 > sp_s % p10:
            break
        if half_s % p10 < sp_s % p10:
            if (mid == 9):
                mid = 0
                half_s += 1
            else:
                mid += 1
            break

    print(half_s, end='')
    print(mid, end='')
    while half_s > 0:
        print(half_s % 10, end='')
        half_s //= 10
    print()
