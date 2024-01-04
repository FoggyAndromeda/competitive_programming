import sys

def main():
    inp = sys.stdin.readlines()

    _, *seeds = inp[0].strip().split()
    seeds = [int(i) for i in seeds]

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

    results = []
    for seed in seeds:
        result = seed
        for now_map in path:
            for (dest_start, src_start, range_len) in mp[now_map]:
                delta = result - src_start
                if delta >= 0 and delta < range_len:
                    result = dest_start + delta
                    break

        results.append(result)
    
    print(min(results))
        
 
main()