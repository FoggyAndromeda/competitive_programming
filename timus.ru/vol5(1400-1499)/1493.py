
def count(s:str):
    left = int(s[0]) + int(s[1]) + int(s[2])
    right = int(s[3]) + int(s[4]) + int(s[5])
    return left == right

a = int(input())

if (count(str(a + 1).rjust(6, '0')) or count(str(a - 1).rjust(6, '0'))):
    print("Yes")
else:
    print("No")