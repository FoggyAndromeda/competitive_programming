p = input()

row = int(p[:-1])
place = p[-1]

if (row < 3):
    if (place in {"A", "D"}):
        print("window")
    else:
        print("aisle")
elif (row < 21):
    if (place in {"A", "F"}):
        print("window")
    else:
        print("aisle")
else:
    if (place in {"A", "K"}):
        print("window")
    elif (place in "CDGH"):
        print("aisle")
    else:
        print("neither")

#1234567890
#abcdefghjk