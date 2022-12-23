a1, a2, a3, a4, a234, a134, a124 = map(int, input().split())
        
a23 = ((a234 - a4) + 2) % 2
a13 = ((a134 - a4) + 2) % 2
a12 = ((a124 - a4) + 2) % 2

if (a1 + a2) % 2 != a12 and (a1 + a3) % 2 != a13 and (a2 + a3) % 2 != a23:
    a4 = (a4 + 1) % 2

if (a1 + a2) % 2 == a12 and (a1 + a3) % 2 != a13 and (a2 + a3) % 2 != a23:
    a3 = (a3 + 1) % 2

if (a1 + a2) % 2 != a12 and (a1 + a3) % 2 == a13 and (a2 + a3) % 2 != a23:
    a2 = (a2 + 1) % 2

if (a1 + a2) % 2 != a12 and (a1 + a3) % 2 != a13 and (a2 + a3) % 2 == a23:
    a1 = (a1 + 1) % 2


print(a1, a2, a3, a4, (a2 + a3 + a4) % 2, (a1 + a3 + a4) % 2, (a1 + a2 + a4) % 2)