import sys

def main():
    ans = 0
    for line in sys.stdin.readlines():
        game_id, game_state = line.strip().split(':')
        winning_numbers, my_numbers = game_state.split('|')
        winning_numbers = {int(i) for i in winning_numbers.split()}
        my_numbers = {int(i) for i in my_numbers.split()}
        intersect = my_numbers.intersection(winning_numbers)
        if len(intersect) != 0:
            ans += pow(2, len(intersect) - 1)
        # print(game_id, winning_numbers, my_numbers, winning_numbers.intersection(my_numbers))
    print(ans)


main()