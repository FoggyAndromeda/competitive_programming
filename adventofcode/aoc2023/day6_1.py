import sys

def main():
    inp = sys.stdin.readlines()
    times = [int(i) for i in inp[0].strip().split()[1:]]
    dists = [int(i) for i in inp[1].strip().split()[1:]]

    ans = 1
    for i in range(len(times)):
        now_ans = 0
        for t in range(times[i] + 1):
            if t * (times[i] - t) > dists[i]:
                now_ans += 1
        print(now_ans) 
        ans *= now_ans
    print(ans)


main()
