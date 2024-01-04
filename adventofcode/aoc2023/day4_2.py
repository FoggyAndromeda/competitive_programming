import sys

def main():
    games_counter = [0] * 1000

    for line in sys.stdin.readlines():
        game_id, game_state = line.strip().split(':')

        _, game_id = game_id.split()
        game_id = int(game_id)
        games_counter[game_id] += 1

        winning_numbers, my_numbers = game_state.split('|')
        winning_numbers = {int(i) for i in winning_numbers.split()}
        my_numbers = {int(i) for i in my_numbers.split()}

        intersect = my_numbers.intersection(winning_numbers)

        for i in range(1, len(intersect) + 1):
            games_counter[game_id + i] += games_counter[game_id] 
        
        # print(game_id, winning_numbers, my_numbers, winning_numbers.intersection(my_numbers))

    # print(games_counter[:20])
    print(sum(games_counter))


main()
