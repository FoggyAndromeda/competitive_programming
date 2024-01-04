import sys

def find_first_digit(s):
    for elem in s:
        if elem.isdigit():
            return elem
    return None

def main():

    ans = 0

    for line in sys.stdin.readlines():
        line = line.strip()
        a = find_first_digit(line)
        b = find_first_digit(line[::-1])
        number_in_line = a + b
        print(number_in_line)
        ans += int(number_in_line)
    print("answer: ", ans)
        
main()