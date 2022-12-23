a, b, c, d = map(int, input().split())

flag = True
while a <= c:
    if flag:
        a += b
    else:
        c -= d
    flag = not flag

if flag:
    print(a)
else:
    print(c)
