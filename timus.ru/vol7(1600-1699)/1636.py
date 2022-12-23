t1, t2 = map(int, input().split())

a = sum(map(int, input().split()))

if (t2 - a * 20 < t1):
    print("Dirty debug :(")
else:
    print("No chance.")