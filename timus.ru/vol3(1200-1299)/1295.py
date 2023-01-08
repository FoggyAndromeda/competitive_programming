def binpow(x, a):
    ans = 1
    while a > 0:
        if (a & 1): 
            ans *= x
        a >>= 1
        x *= x
    return ans

n = int(input())
a = 1 + (1 << n) + binpow(3, n) + (1 << (2 * n))

ans = 0
while (a % 10 == 0):
    ans += 1
    a //= 10
print(ans)