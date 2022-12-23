n = int(input())

count = n + 2
for i in range(n):
    s = input()
    if s.find('+one') != -1:
        count += 1

if count == 13:
    count += 1

print(100 * count)