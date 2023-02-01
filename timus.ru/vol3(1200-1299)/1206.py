def binpow(a, n):
    ans = 1
    while n > 0:
        if (n & 1):
            ans *= a
        a *= a
        n >>= 1
    return ans

print(36 * binpow(55, int(input()) - 1))