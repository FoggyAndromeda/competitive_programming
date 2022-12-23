n, x = map(int, input().split())

p = list(map(int, input().split()))

max_otr = -10001
min_pol = 10001

for elem in p:
    if elem < 0:
        max_otr = max(max_otr, elem)
    else:
        min_pol = min(min_pol, elem)

if x > 0:
    if min_pol < x:
        print("Impossible")
    else:
        print(x, 2 * abs(max_otr) + x)
else:
    if max_otr > x:
        print("Impossible")
    else:
        print(2 * min_pol + abs(x), abs(x))