import sys

ax, ay, bx, by, cx, cy, r = map(int, ' '.join(sys.stdin.readlines()).split())


dab = ((ax - bx) * (ax - bx) + (ay - by) * (ay - by)) ** 0.5
dac = ((ax - cx) * (ax - cx) + (ay - cy) * (ay - cy)) ** 0.5
dcb = ((cx - bx) * (cx - bx) + (cy - by) * (cy - by)) ** 0.5

minans = min(dac, dcb) - r

if dab > 0 and dab * dab + dac * dac >= dcb * dcb and dab * dab + dcb * dcb >= dac * dac:
    minans = abs((ax - cx) * (by - cy) - (bx - cx) * (ay - cy)) / dab - r

minans = max(minans, 0)

maxans = max(0, max(dac, dcb) - r)

print(f"{minans:.2f}\n{maxans:.2f}")
