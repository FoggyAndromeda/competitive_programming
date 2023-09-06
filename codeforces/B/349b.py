v = int(input())

a = list(map(int, input().split()))

if min(a) > v:
    print(-1)
    exit(0)

min_ind = 0

for i in range(1, 9):
    if a[i] <= a[min_ind]:
        min_ind = i

ans_len = v // a[min_ind]

ans = str(min_ind + 1) * ans_len

rest = v - ans_len * a[min_ind]

for i in range(ans_len):
    for c in range(8, min_ind, -1):
        # print(a[c], a[min_ind] + rest)
        if a[c] <= a[min_ind] + rest:
            ans = ans[:i] + str(c + 1) + ans[i + 1:]
            rest = rest + a[min_ind] - a[c]
            break

print(ans) 

