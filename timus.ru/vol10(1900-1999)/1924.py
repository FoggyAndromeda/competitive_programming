n = int(input())

black_moves = n // 2 + n % 2

if black_moves % 2 == 1:
    print("grimy")
else:
    print("black")