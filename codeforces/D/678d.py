from functools import lru_cache

mod = 1_000_000_007

def binpow(a, n):
    res = 1
    while n > 0:
        if n & 1:
            res = (res * a) % mod
        a = (a * a) % mod
        n >>= 1
    return res

@lru_cache
def sum_geom(a, n):
    if n == 1:
        return 1
    if n & 1:
        return (1 + a * sum_geom(a, n - 1)) % mod
    return (sum_geom(a, n // 2) + binpow(a, n // 2) * sum_geom(a, n // 2)) % mod

a, b, n, x = map(int, input().split())

# a^n * x + b * sum_{k = 0}^{n - 1} a^k
res = x * binpow(a, n) + b * sum_geom(a, n)
res %= mod
print(res)
