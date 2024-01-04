import sys

def find_ans(s: str):
    replacements = {
        "1" : 1,
        "2" : 2,
        "3" : 3,
        "4" : 4,
        "5" : 5,
        "6" : 6,
        "7" : 7,
        "8" : 8,
        "9" : 9,
        "one" : 1,
        "two" : 2,
        "three" : 3,
        "four" : 4,
        "five" : 5,
        "six" : 6,
        "seven" : 7,
        "eight" : 8,
        "nine" : 9
    }

    min_indexes = {}
    max_indexes = {}
    for digit in replacements.keys():

        min_index = s.find(digit)
        if min_index != -1:
            min_indexes[digit] = min_index

        max_index = s.rfind(digit)
        if max_index != -1:
            max_indexes[digit] = max_index
         
    min_index = list(min_indexes.keys())[0]

    for digit, index in min_indexes.items():
        if index < min_indexes[min_index]:
            min_index = digit 

    max_index = list(max_indexes.keys())[0]
    for digit, index in max_indexes.items():
        if index > max_indexes[max_index]:
            max_index = digit
    
    return 10 * replacements[min_index] + replacements[max_index]
    


def main():

    ans = 0

    for line in sys.stdin.readlines():
        line = line.strip()
        res = find_ans(line)
        print(res)
        ans += res

    print("answer: ", ans)
 
main()
