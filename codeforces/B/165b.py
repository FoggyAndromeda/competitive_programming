def calc(m, k0):
    res = 0
    k = 1
    while m // k > 0:
        res += m // k
        k *= k0
    return res


n, k = map(int, input().split())

l = -1
r = 1_000_000_000_000

while r - l > 1:
    m = (l + r) >> 1
    if calc(m, k) >= n:
        r = m
    else:
        l = m

# print(calc(r, k))
print(r)
