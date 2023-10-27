import sys

inp = map(int, ' '.join(sys.stdin.readlines()).split())

counter = {}

next(inp)

ans = 0
prefix = 0

for i, elem in enumerate(inp):
    ans += i * elem
    ans -= prefix

    if elem + 1 in counter:
        ans += counter[elem + 1]

    if elem - 1 in counter:
        ans -= counter[elem - 1]

    prefix += elem
    if not elem in counter:
        counter[elem] = 0
    counter[elem] += 1

print(ans)
