from sys import stdin

si = ''

for line in stdin:
    si += line + ' '

s = ''
for c in si:
    if 'a' <= c and c <= 'z':
        s += c
        continue
    s += ' '

s = s.split()

tbus = s.count("trolleybus")
tram = s.count("tram")

if tbus > tram:
    print("Trolleybus driver")
elif tram > tbus:
    print("Tram driver")
else:
    print("Bus driver")
