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

    stars = {}
    for i in range(-1, number_of_lines + 1):
        now_number = 0
        adj_stars = set()
        for j in range(-1, number_of_columns + 1):
            if mp.get((i, j), '.').isdigit():
                now_number *= 10
                now_number += int(mp[(i, j)])

                for dx, dy in deltas:
                    if mp.get((i + dx, j + dy), '.') == '*':
                        adj_stars.add((i + dx, j + dy))
            else:
                for coord in adj_stars:
                    if not coord in stars:
                        stars[coord] = []
                    stars[coord].append(now_number)
                now_number = 0
                adj_stars.clear()
                 
    ans = 0
    for star_coord, adj_coords in stars.items():
        if len(adj_coords) == 0:
            continue
        for i in range(len(adj_coords)):
            for j in range(i):
                ans += adj_coords[i] * adj_coords[j]
    print(ans)

main()
