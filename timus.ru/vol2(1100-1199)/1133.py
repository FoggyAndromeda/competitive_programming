a = [0] * 2002

i, fi, j, fj, k = map(int, input().split())

i += 1001
j += 1001
k += 1001

a[i] = fi
a[j] = fj

if i > j:
    i, j = j, i

fib = [0] * 2002
fib[1] = 1
for h in range(2, len(fib)):
    fib[h] = fib[h - 2] + fib[h - 1]

a[i - 1] = (a[j] - fib[j - i + 1] * a[i]) // fib[j - i]

for h in range(i + 1, len(a)):
    a[h] = a[h - 2] + a[h - 1]

for h in range(i - 2, -1, -1):
    a[h] = a[h + 2] - a[h + 1]

print(a[k])