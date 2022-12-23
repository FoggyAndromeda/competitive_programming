a = int(input())
b = int(input())
c = int(input())

ops = [lambda x, y: x + y, lambda x, y: x - y, lambda x, y: x * y]

ans = 10**9
for i in range(len(ops)):
    for j in range(len(ops)):
        ans = min(ans, ops[i](a, ops[j](b, c)))

print(ans)
