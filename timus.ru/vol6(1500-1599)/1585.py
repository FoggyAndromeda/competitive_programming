names = ["Emperor Penguin", "Macaroni Penguin", "Little Penguin"]

cnt = [0] * 3

n = int(input())

for i in range(n):
    s = input()
    cnt[names.index(s)] += 1

if (cnt[0] > cnt[1] and cnt[0] > cnt[2]):
    print(names[0])
elif (cnt[1] > cnt[0] and cnt[1] > cnt[2]):
    print(names[1])
else:
    print(names[2])