import sys

colors = ["red", "green", "blue"]

def validate(roll):
    colors_values = roll.split(',')
    counter = {}
    for elem in colors_values:
        value, color = elem.strip().split()
        value = int(value)
        counter[color] = value
    
    return counter


def main():
    ans = 0
    for line in sys.stdin.readlines():
        line = line.strip()
        game_id, game_states = line.split(':')
        game_id = int(game_id[game_id.find(' '):])

        counter_max = {}
        for roll in game_states.split(';'):
            now_cnt =  validate(roll)
            for color in colors:
                counter_max[color] = max(counter_max.get(color, 0), now_cnt.get(color, 0))
        
        result = 1
        for color in colors:
            result *= counter_max.get(color, 0) 

        ans += result

    print(ans)

main()
