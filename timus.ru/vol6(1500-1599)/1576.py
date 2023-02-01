def to_minutes(s:str)->int:
    minutes = int(s[:2])
    seconds = int(s[-2:])
    return minutes + (seconds != 0)
    
n1, c1 = map(int, input().split())
n2, t, c2 = map(int, input().split())
n3 = int(input())

k = int(input())

minutes = sum(map(to_minutes, filter(lambda s : s > "00:06", [input() for _ in range(k)])))

ans1 = f"Basic:     {n1 + c1 * minutes}"
ans2 = f"Combined:  {n2 + max(minutes - t, 0) * c2}"
ans3 = f"Unlimited: {n3}"

print(ans1, ans2, ans3, sep='\n')