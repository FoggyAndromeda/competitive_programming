import sys

def main():
    inp = sys.stdin.readlines()

    _, *seeds = inp[0].strip().split()
    seeds = [(int(seeds[i]), int(seeds[i + 1])) for i in range(0, len(seeds), 2)]

    mp = {}
    now_map = ''
    for line in inp[1:]:
        line = line.strip()
        if len(line) == 0:
            continue
        if line[-1] == ':':
            now_map, _ = line.split()
            if not now_map in mp:
                mp[now_map] = []
        else:
            dest_start, src_start, range_len = map(int, line.split())
            mp[now_map].append((dest_start, src_start, range_len))

    path = ["seed-to-soil", "soil-to-fertilizer", "fertilizer-to-water", "water-to-light", "light-to-temperature",
            "temperature-to-humidity", "humidity-to-location"]

    path.reverse()

    loc = 0
    found = False
    while not found:
        result = loc
        for now_map in path:
            for (dest_start, src_start, range_len) in mp[now_map]:
                delta = result -  dest_start
                if delta >= 0 and delta < range_len:
                    result = src_start + delta
                    break
            # print(result, end=' ')
        # print()
        
        for (seed_begin, seed_len) in seeds:
            if result - seed_begin >= 0 and result - seed_begin < seed_len:
                print(loc)
                found = True
        
        loc += 1 

main()