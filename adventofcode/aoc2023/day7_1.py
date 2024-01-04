import sys

card_powers = "23456789TJQKA"[::-1]

def replace_all(s):
    a = []
    for c in s:
        a.append(card_powers.index(c))
    return tuple(a)

def calc_power(s):
    cnt = {}
    for c in s:
        if not c in cnt:
            cnt[c] = 0
        cnt[c] += 1

    cntrs = list(cnt.values())
    cntrs.sort()

    if cntrs[-1] == 5:
        return 0 
    if cntrs[-1] == 4:
        return 1
    if cntrs[-1] == 3 and len(cntrs) == 2:
        return 2
    if cntrs[-1] == 3:
        return 3
    if cntrs[-1] == 2 and len(cntrs) == 3:
        return 4
    if cntrs[-1] == 2:
        return 5 
    return 6

def main():
    hands = [s.split() for s in sys.stdin.readlines()]

    for i in range(len(hands)):
        hands[i] = (calc_power(hands[i][0]), replace_all(hands[i][0]), int(hands[i][1]))

    hands.sort(reverse=True)
    print(hands)

    ans = 0
    for i in range(len(hands)):
        ans += hands[i][2] * (i + 1)
    print(ans)


main()
