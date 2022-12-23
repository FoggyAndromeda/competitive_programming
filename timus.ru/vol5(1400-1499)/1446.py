n = int(input())

d = {
    "Slytherin" : [], 
    "Hufflepuff" : [], 
    "Gryffindor" : [], 
    "Ravenclaw" : []
}

for i in range(2 * n):
    name = input()
    fak = input()
    d[fak].append(name)

for f in ["Slytherin", "Hufflepuff", "Gryffindor", "Ravenclaw"]:
    print(f)
    for name in d[f]:
        print(name)
    print()