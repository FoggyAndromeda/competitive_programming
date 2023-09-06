from math import ceil, floor
from fractions import Fraction
 
 
def gcdext(num1, num2):
    if num1 == 0:
        return (num2, 0, 1)
    else:
        div, x, y = gcdext(num2 % num1, num1)
    return (div, y - (num2 // num1) * x, x)
 
a1, b1, a2, b2, l, r = map(int, input().split())
 
a = a1
b = -a2
c = b2 - b1
 
g, x, y = gcdext(a, b)
 
if c % g != 0:
    print(0)
    exit(0)
 
x *= c // g
y *= c // g
 
lx = Fraction((l - b1), a1)
rx = Fraction((r - b1), a1)
 
ly = Fraction((l - b2) , a2)
ry = Fraction((r - b2) , a2)
 
if max(lx, rx) < 0 or max(ly, ry) < 0:
    print(0)
    exit()
 
lx = max(lx, 0)
rx = max(rx, 0)
ly = max(ly, 0)
ry = max(ry, 0)
 
if lx > rx:
    lx, rx = rx, lx
if ly > ry:
    ly, ry = ry, ly
 
if ceil(lx) > floor(rx) or ceil(ly) > floor(ry):
    print(0)
    exit(0)
 
lx = (lx - x) * g / b
rx = (rx - x) * g / b
 
ly = (ly - y) * g / a
ry = (ry - y) * g / a
 
if lx > rx:
    lx, rx = rx, lx
if ly > ry:
    ly, ry = ry, ly
 
lx = ceil(lx)
rx = floor(rx)
ly = ceil(ly)
ry = floor(ry)
 
ans1 = rx - lx + 1
ans2 = ry - ly + 1
 
print(min(ans1, ans2))
