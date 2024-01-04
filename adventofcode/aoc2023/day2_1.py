import sys

def validate(roll):
    colors_values = roll.split(',')
    counter = {}
    for elem in colors_values:
        value, color = elem.strip().split()
        value = int(value)
        counter[color] = value
    
    if counter.get("red", 0) > 12:
        return False
    if counter.get("blue", 0) > 14:
        return False
    if counter.get("green", 0) > 13:
        return False
    return True


def main():
    ans = 0
    for line in sys.stdin.readlines():
        line = line.strip()
        game_id, game_states = line.split(':')
        game_id = int(game_id[game_id.find(' '):])

        result = 1
        for roll in game_states.split(';'):
            if not validate(roll):
                result = 0

        ans += game_id * result

    print(ans)

main()
