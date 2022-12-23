n = int(input())
a = list(map(int, input().split()))

now_num = -1
now_count = 0

for i in range(n):
    if (now_num != a[i]):
        if (now_count != 0):
            print(now_count, now_num, end = ' ')
        now_num = a[i]
        now_count = 1
    else:
        now_count += 1
print(now_count, now_num)
    