s = input()

while s.find('[') != -1:
    la = s.find('[')
    ra = s.find(']')

    lb = s.find('{')
    rb = s.find('}')

    lc = s.find('(')
    rc = s.find(')')

    a = s[la + 1 : ra]
    b = s[lb + 1 : rb]
    c = s[lc + 1 : rc]

    s = s[:min(la, lb, lc)] + b + ' ' + c + ' ' + a + s[max(ra, rb, rc) + 1:]

print(s.lower().capitalize())



