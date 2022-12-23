d = {
"Alice" : 1
,"Phil" : 1
,"Phoebus" : 1
,"Ariel" : 1
,"Peter" : 1
,"Ralph" : 1
,"Aurora" : 1
,"Olaf" : 1
,"Robin" : 1

,"Bambi" : 2
,"Mulan" : 2
,"Silver" :2
,"Belle" : 2
,"Mowgli" :2
,"Simba" : 2
,"Bolt" : 2
,"Mickey" : 2
,"Stitch" : 2

,"Dumbo" : 3
,"Kuzko" : 3
,"Tarzan" : 3
,"Genie" : 3
,"Kida" : 3
,"Tiana" : 3
,"Jiminy" : 3
,"Kenai" : 3
,"Winnie" : 3
}

n = int(input())

ans = 0
now_on = 1
for i in range(n):
    s = input()
    ans += abs(now_on - d[s])
    now_on = d[s]

print(ans)