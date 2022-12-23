n = int(input())

d = {}

for i in range(n):
    s = input()
    if s in d:
        d[s] += 1
    else:
        d[s] = 1

for k in d.keys():
    if d[k] > 1:
        print(k)