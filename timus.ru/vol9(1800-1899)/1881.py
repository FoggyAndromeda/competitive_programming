h, w, n = map(int, input().split())

num_of_line = 1
num_of_chars = 0

for i in range(n):
    s = input()
    if (num_of_chars + len(s) > w):
        num_of_chars = 0
        num_of_line += 1
    num_of_chars += len(s) + 1

print(num_of_line // h + (num_of_line % h != 0))