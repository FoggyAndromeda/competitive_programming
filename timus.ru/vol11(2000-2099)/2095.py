def calc_ans(n):
    i = 1
    while n > i:
        n -= n // (i + 1)
        i += 1
    return n

l, r = map(int, input().split())

print(calc_ans(r) - calc_ans(l - 1))

