n = int(input())

a = ["16", "06", "68", "88"]

if (n > 4):
    print("Glupenky Pierre")
else:
    print(*a[:n])