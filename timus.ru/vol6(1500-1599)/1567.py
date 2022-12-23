d = {}

for c in range(ord('a'), ord('z') + 1):
    d[chr(c)] = (c - ord('a')) % 3 + 1

d['.'] = 1
d[','] = 2
d['!'] = 3
d[' '] = 1

s = input()

ans = 0

for c in s:
    ans += d[c]
print(ans)