s = input()

fab = s.find("AB")
lab = s.rfind("AB")
fba = s.find("BA")
lba = s.rfind("BA")

if fab != -1 and lba != -1 and lba - fab > 1:
    print("YES")
elif fba != -1 and lab != -1 and lab - fba > 1:
    print("YES")
else: print("NO")