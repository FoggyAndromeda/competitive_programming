d, k, a, b, t = map(int, input().split())

if d <= k:
    print(d * a)
    exit(0)

if a * k + t > b * k:
    print(a * k + b * (d - k))
    exit(0)

"""

car = k * (d // k)
repairs = d // k - 1

if rest by car:
++repairs
car = d

if rest by foot:
foot = d - car

choose minimum
"""

car_dist = k * (d // k)
repairs_cnt = d // k - 1

ans = car_dist * a + repairs_cnt * t + min(t + (d - car_dist) * a, (d - car_dist) * b)

print(ans)
