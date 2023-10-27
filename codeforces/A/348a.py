def check(a, n):
    possible = 0
    for i in a:
        possible += n - i
    return possible >= n

n = int(input())

a = list(map(int, input().split()))

l, r = max(a) - 1, int(1e19)

while r - l > 1:
    m = (l + r) >> 1
    if check(a, m):
        r = m
    else:
        l = m

print(r)
