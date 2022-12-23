n = int(input())

l = 0
r = 100

for i in range(n):
    k, s = input().split()
    k = int(k)
    if s == "hungry":
        l = max(l, k)
    else:
        r = min(r, k)

if (r < l):
    print("Inconsistent")
else:
    print(r)
