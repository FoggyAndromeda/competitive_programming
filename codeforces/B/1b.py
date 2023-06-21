
def to_num(s):
    res = 1

    for i in range(len(s)):
        res += (ord(s[i]) - ord('A')) * (26 ** (len(s) - i - 1))

    for i in range(1, len(s)):
        res += 26 ** i
    return res

def from_num(n):
    res = ''

    l = 0
    nowsum = 0
    while nowsum < n:
        l += 1
        nowsum += 26 ** l
    

    for i in range(l):
        n -= 26 ** i
    
    for i in range(l):
        k = n // (26 ** (l - i - 1))
        n -= k * (26 ** (l - i - 1))
        res += chr(ord('A') + k)

    return res

t = int(input())
for _ in range(t):
    s = input()

    prefix = ''
    for i in range(len(s)):
        if 'A' <= s[i] and s[i] <= 'Z':
            continue
        else:
            prefix = s[:i]
            s = s[i:]
            break
    
    ans = ''
    if 'C' in s:
        r, c = s.split('C')
        ans = from_num(int(c)) + r
    else:
        ans = "R" + s + "C" + str(to_num(prefix))
    
    print(ans)