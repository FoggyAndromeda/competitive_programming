n, k = map(int, input().split())

a = list(map(lambda x : x.rjust(4, ' '), input().split()))

height = n // k + (n % k != 0)

for i in range(height):
    for j in range(k):
        if i + height * j < n:
            print(a[i + height * j], end='')
    print() 