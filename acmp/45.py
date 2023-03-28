n = int(input())

ans = 0

if (n == 0):
    print(10)
    exit(0)
if (n == 1):
    print(1)
    exit(0)

for i in range(9, 1, -1):
    while n % i == 0:
        ans = 10 * ans + i;
        n //= i

if (n != 1):
    print(-1)
else:
    print(''.join(reversed(str(ans))))