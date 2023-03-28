n = int(input())

a, b = 0, 1

mod = 1_000_000_007

for _ in range(n):
    a, b = (2 * a + b) % mod, (3 * a) % mod

print(b)