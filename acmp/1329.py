from math import acos, sin
import sys

# sys.stdin = open("input.in")
inp = ' '.join(sys.stdin.readlines())

x1, y1, r1, x2, y2, r2 = map(float, inp.split())

pi = 3.1415926535897932384626433832795

oodist = ((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2)) ** 0.5

if oodist >= r1 + r2:
    print(f"{0:.2f}")
    exit(0)

if oodist <= abs(r1 - r2):
    print(f"{pi * min(r1, r2) * min(r1, r2):.2f}")
    exit(0)

alpha = 2 * acos((r1 * r1 - r2 * r2 + oodist * oodist) / (2 * r1 * oodist))
beta = 2 * acos((r2 * r2 - r1 * r1 + oodist * oodist) / (2 * r2 * oodist))

s1 = r1 * r1 * (alpha - sin(alpha)) / 2
s2 = r2 * r2 * (beta - sin(beta)) / 2

print(f"{s1 + s2:.2f}")
