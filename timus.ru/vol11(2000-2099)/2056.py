n = int(input())

marks = []

for i in range(n):
    marks.append(int(input()))

avg = sum(marks) / n

if 3 in marks:
    print("None")
elif avg == 5.0:
    print("Named")
elif avg >= 4.5:
    print("High")
else:
    print("Common")