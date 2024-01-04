import sys

deltas = [(1, -1), (1, 0), (1, 1), (0, -1), (0, 1), (-1, -1), (-1, 0), (-1, 1)]

def main():
    mp = {}
    number_of_lines = 0
    number_of_columns = 0
    for line in sys.stdin.readlines():
        line = line.strip()
        number_of_lines += 1
        number_of_columns = len(line)

        for i in range(len(line)):
            mp[(number_of_lines, i)] = line[i]

    ans = 0
    for i in range(-1, number_of_lines + 1):
        now_number = 0
        have_char = False
        for j in range(-1, number_of_columns + 1):
            if mp.get((i, j), '.').isdigit():
                now_number *= 10
                now_number += int(mp[(i, j)])

                for dx, dy in deltas:
                    have_char = have_char or not (mp.get((i + dx, j + dy), '.') in "0123456789.")
            else:
                if now_number != 0:
                    print(have_char, now_number)
                if have_char:
                    ans += now_number
                have_char = False
                now_number = 0
    print(ans)

main()
